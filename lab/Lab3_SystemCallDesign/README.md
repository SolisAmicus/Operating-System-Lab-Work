**作业标题：实验课题作业3——Linux系统调用设计与添加实现**

**作业内容**：

**基本功能要求**：

1、实验过程可具体采取 VMware 虚拟机创建和（KylinOS、LoongSonOS、openEulerOS、Ubuntu 或 RedHat 等）Linux 系统安装、Linux 内核源码下载和编译启用测试、添加实现新增系统调用后的 Linux 内核源码编译启用测试等三大步骤；

2、设计和实现一个系统调用（譬如关于进程资源使用状况检测功能的系统调用）；

3、设计和实现关于新增系统调用直接调用的应用测试例程；

4、上述所有实现均应在虚拟机平台及自己下载修改和编译的Linux操作系统版本上编译运行和测试验证通过。

其中，关于进程资源使用状况检测的系统调用所对应的用户级函数原型可为：

`int get_process_usage(pid_t zPID, struct zgs_rusage* zRU);`

- 第一个参数用来传入指定进程的进程标识符
- 第二个参数用来返回指定进程的资源使用状况信息

而关于进程资源使用状况信息的数据结构类型 struct zgs_rusage 的定义如下：

```
struct zgs_rusage {
	struct timeval ru_utime; // 进程在用户态的执行时间（以秒和微秒为单位）
	struct timeval ru_stime; // 进程在系统态的执行时间（以秒和微秒为单位）
	long     ru_majflt; // 需要物理输入输出操作的页面错误次数
	long     ru_minflt; // 无需物理输入输出操作的页面错误次数
	long     ru_nswap; // 进程置换出内存的次数
};
```

建议上述类型名称中的 zgs 替代为你自己姓名拼音的字母缩写。

需要指出的是，该系统调用是 Linux 内核自身的系统调用 getrusage() 的一个变种，所以建议首先研读和分析 getrusage() 及 sys_getrusage() 等相关源代码，以便在此基础上形成自己的系统调用函数设计方案。

**实验报告撰写和提交要求**：

1、实验报告内容，须涵盖开发环境、运行环境、测试环境、源码清单、实验步骤、技术难点及解决方案、关键数据结构和算法流程、Linux 内核补丁包源码（针对添加系统调用后/前的两版原版，利用 diff 命令生成）、应用测试例程源码、编译运行测试过程及结果截图、疑难解惑及经验教训、结论与体会等；

2、在实验报告内容（如运行结果截图等适当位置）中应有机融入个人姓名、学号、计算机系统信息等凸显个人标记特征的信息；

3、实验报告文档提交格式可为 Word 文档、WPS 文档或 PDF 文档；

4、除实验报告外，还需提交 Linux 内核补丁包源码、应用测试例程源码等。