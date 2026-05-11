#include "memlayout.h"
#include "riscv.h"
#include "string.h"
#include "defs.h"
#include "vm.h"

// Copy from kernel to user.
// Copy len bytes from src to virtual address dstva in a given page table.
// Return 0 on success, -1 on error.
int copy_to_user(struct mm *mm, uint64 __user dstva, char *src, uint64 len) {
    uint64 n, va0, pa0;
    pte_t *pte;

    while (len > 0) {
        va0 = PGROUNDDOWN(dstva);
        pte = walk(mm, va0, 0);
        if (pte == NULL || !(*pte & PTE_V) || !(*pte & PTE_U))
            return -EINVAL;
        if ((*pte & PTE_A3_COW) && !(*pte & PTE_W)) {
            void *newpa = kallocpage();
            if (!newpa)
                return -ENOMEM;
            uint64 oldpa = PTE2PA(*pte);
            memmove((void *)PA_TO_KVA(newpa), (void *)PA_TO_KVA(oldpa), PGSIZE);
            page_refcnt_increase((uint64)newpa);

            uint64 flags = (PTE_FLAGS(*pte) | PTE_W | PTE_D) & ~PTE_A3_COW;
            *pte = PA2PTE(newpa) | flags;
            sfence_vma();

            int8 cnt = page_refcnt_decrease(oldpa);
            if (cnt == 0)
                kfreepage((void *)oldpa);
        }
        pa0 = PTE2PA(*pte);
        n = PGSIZE - (dstva - va0);
        if (n > len)
            n = len;
        memmove((void *)(PA_TO_KVA(pa0) + (dstva - va0)), src, n);

        len -= n;
        src += n;
        dstva = va0 + PGSIZE;
    }
    return 0;
}

// Copy from user to kernel.
// Copy len bytes to dst from virtual address srcva in a given page table.
// Return 0 on success, -1 on error.
int copy_from_user(struct mm *mm, char *dst, uint64 __user srcva, uint64 len) {
    uint64 n, va0, pa0;

    while (len > 0) {
        va0 = PGROUNDDOWN(srcva);
        pa0 = walkaddr(mm, va0);
        if (pa0 == 0)
            return -EINVAL;
        n = PGSIZE - (srcva - va0);
        if (n > len)
            n = len;
        memmove(dst, (void *)(PA_TO_KVA(pa0) + (srcva - va0)), n);

        len -= n;
        dst += n;
        srcva = va0 + PGSIZE;
    }
    return 0;
}

// Copy a null-terminated string from user to kernel.
// Copy bytes to dst from virtual address srcva in a given page table,
// until a '\0', or max.
// Return 0 on success, -1 on error.
int copystr_from_user(struct mm *mm, char *dst, uint64 __user srcva, uint64 max) {
    uint64 n, va0, pa0, kva0;
    int got_null = 0, len = 0;

    while (got_null == 0 && max > 0) {
        va0 = PGROUNDDOWN(srcva);
        pa0 = walkaddr(mm, va0);
        if (pa0 == 0)
            return -EINVAL;
        n = PGSIZE - (srcva - va0);
        if (n > max)
            n = max;

        kva0    = PA_TO_KVA(pa0);
        char *p = (char *)(kva0 + (srcva - va0));
        while (n > 0) {
            if (*p == '\0') {
                *dst     = '\0';
                got_null = 1;
                break;
            } else {
                *dst = *p;
            }
            --n;
            --max;
            p++;
            dst++;
            len++;
        }

        srcva = va0 + PGSIZE;
    }
    if (got_null) {
        return 0;
    } else {
        return -1;
    }
}
