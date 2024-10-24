#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

struct ljj_rusage {
    struct timespec ru_utime;  // 用户态执行时间（秒+纳秒）
    struct timespec ru_stime;  // 系统态执行时间（秒+纳秒）
    long           ru_majflt;  // 页面错误次数（需要物理I/O）
    long           ru_minflt;  // 页面错误次数（无需物理I/O）
    long           ru_nswap;   // 进程换出次数
};

int main(int argc, char *argv[]) {
    pid_t pid;
    if (argc == 2) {
        pid = atoi(argv[1]);
        printf("Using provided PID: %d\n", pid);
    } else {
        pid = getpid();
        printf("No PID provided. Using current PID: %d\n", pid);
    }

    struct ljj_rusage usage;

    long result = syscall(462, pid, &usage);
    
    if (result == -1) {
        perror("System call failed");
        return 1;
    }

    printf("Process PID: %d\n", pid);
    printf("User time: %lld.%09ld seconds\n", (long long)usage.ru_utime.tv_sec, usage.ru_utime.tv_nsec);
    printf("System time: %lld.%09ld seconds\n", (long long)usage.ru_stime.tv_sec, usage.ru_stime.tv_nsec);
    printf("Major faults: %ld\n", usage.ru_majflt);
    printf("Minor faults: %ld\n", usage.ru_minflt);
    printf("Swap count: %ld\n", usage.ru_nswap);

    return 0;
}
