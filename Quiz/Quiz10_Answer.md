# Quiz 10

## 第一题：Deadlock Detection 与 Safe State

**填空答案：**

- 填空 1：No
- 填空 2：No

解释：

- 当前 Allocation 总和为 `(5, 4, 4)`，总资源为 `(5, 5, 4)`，所以 Available = `(0, 1, 0)`。
- 按 Request 矩阵做 deadlock detection：P3 请求 `(0,0,0)` 可完成，之后可依次完成 P4、P2、P1，因此系统不处于 deadlock。
- 但按 Max 矩阵计算安全性时，初始 Available = `(0,1,0)` 只能先完成 P3，再完成 P4，此后剩余资源不足以满足 P1 或 P2 的 Need，所以不是 safe state。

---

## 第二题：Banker's Algorithm 填空

**填空答案：**

- Blank 1：2
- Blank 2：1
- Blank 3：P2
- Blank 4：P1
- Blank 5：Yes

Need[P2] = Max[P2] - Allocation[P2] = `(3,2,2) - (1,1,1) = (2,1,1)`。

按资源总数 `(9,6,8)` 和 Allocation 总和 `(4,2,4)` 计算，Available = `(5,4,4)`。一个安全序列可为：

`P0 -> P2 -> P3 -> P1`

若 P1 请求 `(1,0,1)`：

- Request <= Need[P1] = `(2,2,2)`。
- Request <= Available。
- 试分配后仍可找到安全序列，因此可立即授予。

---

## 第三题：Programmed I/O

**填空答案：**

- Blank 1：port-mapped
- Blank 2：memory-mapped

解释：port-mapped I/O 使用专门的 I/O 端口和特权 I/O 指令；memory-mapped I/O 把设备寄存器映射到物理地址空间，通过普通 load/store 访问。

---

## 第四题：Polling vs. Interrupts

**正确选项：B、C、D**

- A：慢设备更适合中断，否则轮询会浪费大量 CPU。
- B：中断允许 CPU 在 I/O 完成前去执行其他任务。
- C：混合方法可以先短暂轮询，再退回中断机制。
- D：轮询在设备很快或等待时间很短时效果较好。
- E：中断并不总是优于轮询。

---

## 第五题：DMA

**正确选项：A、D、E**

- A：DMA 可在 I/O 设备和内存之间直接搬运数据，不需要 CPU 逐字节复制。
- B：DMA 完成后仍通常需要中断通知 CPU。
- C：使用 DMA 时 CPU 不负责逐字节复制。
- D：DMA 完成后会通过中断告知 CPU。
- E：DMA 可能通过 cycle stealing 占用总线周期，但总体仍比 programmed I/O 高效。

---

## 第六题：Modern SSDs

**正确选项：A、C、E**

- A：SSD 没有机械移动部件，因此没有寻道时间和旋转延迟。
- B：NAND flash 写入前通常需要先擦除，不能直接页级覆盖。
- C：3D NAND 通过垂直堆叠提高存储密度。
- D：QLC 每单元 4 bit，容量高但耐久性低于 SLC。
- E：NVMe SSD 通过 PCIe 连接，并支持大量深队列。
