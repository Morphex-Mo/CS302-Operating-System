# CS302 Operating System 学习记录

最后更新：2026-06-30

这是一个用于记录 CS302（Operating System）课程学习过程的仓库，包含 Assignment、Lab、Quiz 与课程相关资料。内容以实验代码、课程练习和复习笔记为主，仅供学习交流参考。

## 仓库说明

- 课程：CS302 Operating System
- 内容：课程作业代码、实验练习、Quiz 资料、答案与学习记录
- 目的：复习知识点、沉淀实验过程、便于阶段性回顾

## 目录结构（关键部分）

```text
CS302-Operating-System/
├── LICENSE
├── README.md
├── readme maintenance.md
├── Assignment/
│   ├── assignment1-Preemption/
│   ├── assignment2-uaccess/
│   ├── assignment3-cow/
│   ├── assignment4-sched/
│   └── assignment5-semaphore/
├── Lab/
│   ├── lab2/
│   ├── lab3/
│   ├── lab4/
│   ├── lab5/
│   ├── lab6/
│   ├── lab7/
│   ├── lab8/
│   ├── lab9/
│   ├── lab10/
│   ├── lab11/
│   ├── lab12/
│   ├── lab13/
│   └── os-riscv-refs/
├── Quiz/
│   ├── Quiz2.pdf
│   ├── Quiz2_Answer.md
│   ├── Quiz3.pdf
│   ├── Quiz4.pdf
│   ├── Quiz5.pdf
│   ├── Quiz5_Answer.md
│   ├── Quiz6.pdf
│   ├── Quiz6_Answer.md
│   ├── Quiz7.pdf
│   └── Quiz7_Answer.md
├── lecture/
├── project/
│   └── project-team5/
└── README.md
```

## Assignment

- `Assignment/assignment1-Preemption/`：抢占相关作业目录。
- 包含内核源码目录 `os/`、构建配置 `Makefile`、实验报告 `report.md` 与辅助脚本 `scripts/`。
- `Assignment/assignment2-uaccess/`：用户态访问相关作业目录，包含内核源码、用户程序与相关脚本。
 - `Assignment/assignment3-cow/`：Copy-on-write（写时复制）相关作业目录。
 - `Assignment/assignment4-sched/`：调度相关作业目录。
 - `Assignment/assignment5-semaphore/`：信号量相关作业目录。

## Lab

- `Lab/lab2/` 到 `Lab/lab8/`：课程实验代码与练习。
- `Lab/os-riscv-refs/`：RISC-V 参考资料。
 - `Lab/lab2/` 到 `Lab/lab11/`：课程实验代码与练习（含 lab9/lab10/lab11）。
 - `Lab/lab2/` 到 `Lab/lab13/`：课程实验代码与练习（含 lab12/lab13）。
 - `Lab/os-riscv-refs/`：RISC-V 参考资料。

## Quiz

- `Quiz/Quiz2.pdf`、`Quiz/Quiz3.pdf`、`Quiz/Quiz4.pdf`、`Quiz/Quiz5.pdf`：课堂 Quiz 题目资料。
- `Quiz/Quiz2_Answer.md`、`Quiz/Quiz5_Answer.md`：已整理的 Quiz 答案与复习记录。
 - `Quiz/Quiz2.pdf` 到 `Quiz/Quiz7.pdf`：课堂 Quiz 题目资料（已收集至 Quiz7）。
 - `Quiz/Quiz2_Answer.md`、`Quiz/Quiz5_Answer.md`、`Quiz/Quiz6_Answer.md`、`Quiz/Quiz7_Answer.md`：整理的 Quiz 答案与复习记录（如有）。

## Project

- `project/project-team5/`：团队项目协作区，包含完整的操作系统项目代码、文档和说明文件。
- 详情参考：https://github.com/sustech-os-2026spring/project-team5/tree/main

## 快速开始（示例）

以 Assignment 1 为例：

```bash
cd Assignment/assignment1-Preemption
make
```

以 Assignment 2 为例：

```bash
cd Assignment/assignment2-uaccess
make
```

以 Assignment 5 为例：

```bash
cd Assignment/assignment5-semaphore
make
```

以 Lab2 为例：

```bash
cd Lab/lab2
make
```

以 Lab8 为例：

```bash
cd Lab/lab8
make
```

以 Project 为例：

```bash
cd project/project-team5
make
```

## 使用声明

- 本仓库为个人学习资料整理，不保证完全正确。
- 仅供参考，请结合课程教材与课堂内容独立完成作业。
- 如有错误或理解偏差，欢迎交流指正。
