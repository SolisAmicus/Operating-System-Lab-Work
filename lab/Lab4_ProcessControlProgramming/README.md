**作业标题：实验课题作业4——Linux进程控制操作应用编程**

**作业内容**：

**基本功能要求**：

1、采用 C 语言设计和编写一个简单的进程创建应用例程。要求在所创建的子进程中正确显示其自身的进程号及其父进程的进程号，而在主进程中正确显示其自身的进程号及其所创建的子进程的进程号。

2、采用 C 语言设计和编写程序实现循环显示字符串 “Viva la chine! ” 的功能，并在用户从键盘键入 Ctrl C 时终止循环，显示 “Au revoir! ” 后结束。

3、采用 C 语言设计和编写程序实现父子进程的同步。父进程首先显示 “Program started… ”，接着创建一个子进程，在父进程中循环显示五次 “How are you? ”，然后发软中断信号给子进程，再等待子进程终止后输出结束信息 “I am fine too! Program ended! ”，然后终止执行。子进程中循环显示 “I am fine, thanks, and you? ”，当接收到父进程发来的软中断信号后停止循环，显示 “Child exited! ” 并终止执行。

4、采用 C 语言设计和编写程序实现基于无名管道的父子进程的通信过程。父进程首先显示 “Program started… ”，接着创建一个无名管道和一个子进程，在父进程中向管道文件依次写入每个大写英文字母 60 遍（即 60 个 A、60 个 B、……）同时显示所发送的字母譬如 “I am sending A… ”，再等待子进程终止后输出结束信息 “Program ended! ”，然后终止执行。子进程中从管道接收数据，并显示譬如 “I am receiving A… ”，当接收到父进程发来的软中断信号后停止循环，显示 “Child exited! ” 并终止执行。

**实验报告撰写和提交要求**：

1、实验报告内容，须涵盖开发环境、运行环境、测试环境、源程序文件及源码清单（包括 Makefile 文件，如果有的话）、实验步骤、技术难点及解决方案、关键数据结构和算法流程、编译运行测试过程及结果截图、疑难解惑及经验教训、结论与体会等；

2、在实验报告内容（如运行结果截图等适当位置）中应有机融入个人姓名、学号、计算机系统信息等凸显个人标记特征的信息；

3、实验报告文档提交格式可为 Word 文档、WPS 文档或 PDF 文档；

4、除实验报告外，还需提交 Linux 进程控制操作应用例程源码等。