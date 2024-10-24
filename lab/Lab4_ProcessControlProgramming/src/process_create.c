#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork(); // 创建子进程

    if (pid < 0) {
        // 创建子进程失败
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        // 子进程
        printf("子进程: 我的PID是 %d, 父进程PID是 %d\n", getpid(), getppid());
    } else {
        // 父进程
        printf("父进程: 我的PID是 %d, 子进程PID是 %d\n", getpid(), pid);
    }

    return 0;
}
