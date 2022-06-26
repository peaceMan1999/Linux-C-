#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act, oact;

void handler(int signo)
{
    printf("get a signo : %d\n", signo);
    sigaction(SIGINT, &oact, NULL);
}

int main()
{
    sigemptyset(&act.sa_mask);
    act.sa_handler = handler;
    act.sa_flags = 0;

    sigaction(SIGINT, &act, &oact);
    while (1){
        printf("hello\n");
        sleep(1);
    }

    return 0;
}
