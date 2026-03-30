checkpoint1
![alt text](checkpoint1_result.png)

checkpoint2
根因是：你在内核 Trap 里调用了调度，但没有保存/恢复 CSR 的 sstatus 和 sepc，导致后续 sret 用了“别的上下文”留下的 sstatus。

关键点在这里：

在 entry.S 的 kernel_trap_entry 末尾，返回使用的是 sret。
根据 RISC-V Privileged Spec 4.1.1，执行 sret 时：
先按 sstatus.SPP 决定返回到 S/U
然后硬件会把 SPP 清零
你的 trap.c 里 kernel_trap 在定时器中断路径会调用 yield（你还临时改了 inkernel_trap 来允许它调度）。
一旦在 Trap 中 yield -> sched -> swtch，CPU 会去跑别的线程/进程；期间别的 Trap/sret 会改写当前 hart 的 sstatus/sepc。
等原来那个“卡在 kernel_trap 里”的上下文被切回来时，kernel_trap_entry 直接 sret，但此时 CSR 里的 sstatus 可能已经是 SPP=0（被之前某次 sret 清过），于是这次 sret 真的把内核返回到了 U-mode。
下一次再进 kernel_trap 时，你的检查 (r_sstatus() & SSTATUS_SPP)==0 就触发，看到的就是 SPP:U panic。
为什么“总在第一个进程 exit 后更容易出现”：

exit 会触发一次明确的 sched 切换；
同时其它进程很多都停在 kernel_trap 的 yield 处（你提示里说的现象），这会制造大量“Trap 内调度 -> 回来继续 sret”的场景；
因此更容易踩到被污染/过期的 sstatus.SPP。
一句话总结：不是你显式清了 SPP，而是 sret 硬件会清；你在 Trap 中调度但没保护 sstatus/sepc，导致恢复时用错了 SPP。
![alt text](checkpoint2_result.png)