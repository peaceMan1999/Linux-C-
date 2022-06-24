#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void printPending(const sigset_t *set)
{
    int i = 1;
    for (; i <= 31; i++){
        if (sigismember(set, i) == 0){
            printf("0 ");
        }
        else{
            printf("1 ");
        }
    }
    printf("\n");
}

void handler(int signo)
{
    printf("信号恢复\n");
}

int main()
{
    // 设置一个信号屏蔽字，让信号一直被pending
    sigset_t set, oset;

    signal(2, handler);
    sigemptyset(&set);
    sigemptyset(&oset);

    //sigfillset(&set);

    sigaddset(&set, 2);

    sigprocmask(SIG_SETMASK, &set, &oset);
    sigset_t pending;
    int count = 0;
    while (1){
        if (count == 10){
            sigprocmask(SIG_SETMASK, &oset, NULL);
        }
        count++;
        sigpending(&pending);
        printPending(&pending);
        sleep(1);
    }

    return 0;
}
