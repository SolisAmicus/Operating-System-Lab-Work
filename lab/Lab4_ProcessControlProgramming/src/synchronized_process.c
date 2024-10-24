#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

// 软中断标志位
volatile sig_atomic_t stop = 0;

// 信号处理函数，设置标志位
void handle_sigusr1(int sig) {
    stop = 1;
}

int main() {
    // 捕捉软中断信号 SIGUSR1
    signal(SIGUSR1, handle_sigusr1);

    pid_t pid = fork(); // 创建子进程

    if (pid < 0) {
        // fork 失败
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        // 子进程逻辑
        while (!stop) {
            printf("子进程: I am fine, thanks, and you?\n");
            sleep(1); // 延迟1秒
        }
        printf("子进程: Child exited!\n");
        exit(0); // 终止子进程
    } else {
        // 父进程逻辑
        printf("父进程: Program started...\n");
        for (int i = 0; i < 5; i++) {
            printf("父进程: How are you?\n");
            sleep(1); // 延迟1秒
        }

        // 向子进程发送 SIGUSR1 信号，通知子进程结束
        kill(pid, SIGUSR1);

        // 等待子进程终止
        wait(NULL);

        // 子进程结束后，父进程输出结束信息
        printf("父进程: I am fine too! Program ended!\n");
    }

    return 0;
}
