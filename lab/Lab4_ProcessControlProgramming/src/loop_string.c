#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t stop;

void handle_sigint(int sig) {
    stop = 1;
}

int main() {
    signal(SIGINT, handle_sigint); // 捕捉 Ctrl+C 信号

    while (!stop) {
        printf("Viva la chine!\n");
        sleep(1); // 延迟1秒
    }

    printf("\nAu revoir!\n");
    return 0;
}
