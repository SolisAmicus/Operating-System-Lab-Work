#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

volatile sig_atomic_t stop = 0;

void handle_sigusr1(int sig) {
    stop = 1;
}

int main() {
    int fd[2];
    char ch;
    pipe(fd); // 创建无名管道

    signal(SIGUSR1, handle_sigusr1); // 捕捉软中断信号

    pid_t pid = fork(); // 创建子进程

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        // 子进程：读取管道数据
        close(fd[1]); // 关闭写端
        while (!stop) {
            if (read(fd[0], &ch, 1) > 0) {
                printf("I am receiving %c...\n", ch);
            }
        }
        printf("Child exited!\n");
        close(fd[0]); // 关闭读端
    } else {
        // 父进程：写入管道数据
        close(fd[0]); // 关闭读端
        char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 60; j++) {
                write(fd[1], &letters[i], 1);
                printf("I am sending %c...\n", letters[i]);
                usleep(10000); // 延迟10ms
            }
        }
        kill(pid, SIGUSR1); // 给子进程发送软中断信号
        wait(NULL); // 等待子进程终止
        printf("Program ended!\n");
        close(fd[1]); // 关闭写端
    }

    return 0;
}
