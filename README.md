# CS302 Operating System 学习记录

最后更新：2026-04-01

这是一个用于记录 CS302（Operating System）课程学习过程的仓库，包含 Assignment、Lab、Quiz 与课程相关资料。内容仅供学习交流参考。

## 仓库说明

- 课程：CS302 Operating System
- 内容：课程作业代码、实验练习、Quiz 答案与学习记录
- 目的：复习知识点、沉淀实验过程、便于阶段性回顾

## 目录结构（关键部分）

```text
CS302-Operating-System/
├── LICENSE
├── README.md
├── readme maintenance.md
├── Assignment/
│   └── assignment1-Preemption/
│       ├── Makefile
│       ├── report.md
│       ├── os/
│       └── scripts/
├── Lab/
│   ├── lab2/
│   ├── lab3/
│   ├── lab4/
│   ├── lab5/
│   ├── lab6/
│   └── os-riscv-refs/
├── Quiz/
│   ├── Quiz2_Answer.md
│   └── Quiz5_Answer.md
└── lecture/
```

## Assignment

- `Assignment/assignment1-Preemption/`：抢占相关作业目录。
- 包含内核源码目录 `os/`、构建配置 `Makefile`、实验报告 `report.md` 与辅助脚本 `scripts/`。

## Lab

- `Lab/lab2/` 到 `Lab/lab6/`：课程实验代码与练习。
- `Lab/os-riscv-refs/`：RISC-V 参考资料。

## Quiz

- `Quiz/Quiz2_Answer.md`、`Quiz/Quiz5_Answer.md`：课堂 Quiz 答案与复习记录。

## 快速开始（示例）

以 Assignment 1 为例：

```bash
cd Assignment/assignment1-Preemption
make
```

## 使用声明

- 本仓库为个人学习资料整理，不保证完全正确。
- 仅供参考，请结合课程教材与课堂内容独立完成作业。
- 如有错误或理解偏差，欢迎交流指正。
