# CS302 Operating System 学习记录

这是一个大三学生在学习 CS302（Operating System）课程过程中的课堂 Quiz、Lab 习题与个人笔记整理仓库，内容仅供借鉴与学习交流使用。

## 仓库说明

- 课程：CS302 Operating System
- 内容：课堂 Quiz 答案与解析、Lab 代码练习、阶段性学习记录
- 目的：复习知识点、梳理实验流程、沉淀课程学习过程

## 目录结构

```text
CS302-Operating-System/
├── LICENSE
├── README.md
├── Lab/
│   └── lab1/
│       ├── main.c
│       ├── utils.c
│       ├── utils.h
│       ├── test1.c
│       └── Makefile
└── Quiz/
    └── Quiz2_Answer.txt
```

## Lab

当前包含 `lab1`：

- `main.c`：主程序示例，调用加法函数并输出结果
- `utils.c` / `utils.h`：工具函数声明与实现
- `test1.c`：补充测试代码
- `Makefile`：跨平台编译与清理规则

### 运行方式

```bash
cd Lab/lab1
make
```

运行程序：

- Windows：`./main.exe`
- Linux/macOS：`./main`

清理构建文件：

```bash
make clean
```

## Quiz

`Quiz/Quiz2_Answer.txt` 收录了课堂 Quiz 的答案与中文解析，便于课后复习与查漏补缺。

## 使用声明

- 本仓库内容为个人学习资料整理，不保证完全正确。
- 仅供参考，请结合课程教材、课堂内容与个人理解独立完成作业。
- 如有错误或理解偏差，欢迎交流指正。
