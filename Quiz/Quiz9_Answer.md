# Quiz 9

## 第一题：Race Condition 下变量 X 的可能结果

**正确选项：A、B、C、D**

初值 `X = 0`，三个线程分别执行 `X = X + 2`、`X = X - 1`、`X = 0`。在不同交错下，最终可能为：

- `0`：最后由线程 C 写入 `0`。
- `1`：例如 C 先写 `0`，A 写 `2`，B 再基于 `2` 写 `1`。
- `2`：最后由线程 A 基于 `0` 写入 `2`。
- `-1`：最后由线程 B 基于 `0` 写入 `-1`。

`-2` 不可达，因为只有一次 `X = X - 1`。

---

## 第二题：Semaphore

**正确选项：B、D**

- A：初值为 3 的信号量允许最多 3 个进程同时通过，不能保证互斥。
- B：`sem_wait()` 和 `sem_post()` 必须以原子方式更新信号量，否则自身会有竞争条件。
- C：栈是 LIFO，不能保证 bounded waiting；队列更合适。
- D：信号量是典型的 sleep-based 同步机制之一。
- E：生产者-消费者问题中不能随意交换 `wait(&fill)` 与 `wait(&mutex)` 的顺序，否则可能死锁。

---

## 第三题：Safe State 与 Deadlock State

**正确选项：C、D、E**

- A：unsafe 不一定已经 deadlock。
- B：unsafe 不一定已经存在 circular wait。
- C：safe state 一定不是 deadlock state。
- D：safe state 未来仍可能因为后续请求/错误分配策略进入 deadlock。
- E：deadlock state 一定不是 safe state，因此必然 unsafe。

---

## 第四题：Deadlock Prevention 与 Avoidance

**正确选项：A、C、D**

- A：deadlock prevention 通过破坏四个必要条件中的至少一个来预防死锁。
- B：互斥通常由资源性质决定，不能总是去掉。
- C：Banker's Algorithm 是 deadlock avoidance，需要提前知道最大资源需求。
- D：deadlock avoidance 避免进入 unsafe state；但 unsafe state 不等于已经 deadlock。
- E：资源类型全序并按递增顺序请求，破坏的是 circular wait，不是 hold and wait。

---

## 第五题：Resource-allocation Graph

**正确选项：A、C、D、E**

- A：请求边从进程/线程指向资源类型，分配边从资源类型指向进程/线程。
- B：若资源类型有多个实例，有环不一定意味着死锁。
- C：若每类资源只有一个实例，有环则意味着死锁。
- D：资源分配图可表示谁持有资源、谁正在等待资源。
- E：资源分配图无环则系统不可能处于死锁状态。

---

## 第六题：Banker's Algorithm

### (a) Need 矩阵

`Need = Max - Allocation`：

| Process | Need (A B C) |
| --- | --- |
| P0 | 7 4 3 |
| P1 | 1 2 2 |
| P2 | 6 0 0 |
| P3 | 0 1 1 |
| P4 | 4 3 1 |

### (b) 初始状态是否安全

初始 `Available = (3, 3, 2)`，系统处于安全状态。

一个安全序列是：

`P1 -> P3 -> P4 -> P0 -> P2`

推导：

- Work = `(3,3,2)`，P1 need `(1,2,2)` 可满足，释放后 Work = `(5,3,2)`。
- P3 need `(0,1,1)` 可满足，释放后 Work = `(7,4,3)`。
- P4 need `(4,3,1)` 可满足，释放后 Work = `(7,4,5)`。
- P0 need `(7,4,3)` 可满足，释放后 Work = `(7,5,5)`。
- P2 need `(6,0,0)` 可满足，释放后 Work = `(10,5,7)`。

### (c) P1 请求 `(1, 0, 2)` 是否可立即授予

可以授予。

- Request `(1,0,2)` <= Need[P1] `(1,2,2)`。
- Request `(1,0,2)` <= Available `(3,3,2)`。
- 试分配后 Available = `(2,3,0)`，P1 的 Need 变为 `(0,2,0)`，仍存在安全序列：

`P1 -> P3 -> P4 -> P0 -> P2`
