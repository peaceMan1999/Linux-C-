#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

volatile int flag = 0;
//int flag = 0; +O3

void handler(int signo)
{
    printf("get a signal: %d\n", signo);

    flag = 1;
}

int main()
{
    signal(2, handler);
    while(!flag);
    
    printf("happy ending\n");
    return 0;
}


//struct sigaction act, oact;
//
//void handler(int signo)
//{
//    printf("get a signal: %d\n",signo);
//    
//    
//    sigaction(SIGINT, &oact, NULL);
//}
//
//int main()
//{
//    struct sigaction act, oact;
//    memset(&act, 0, sizeof(act));
//    memset(&oact, 0, sizeof(act));
//
//    act.sa_handler = handler;
//    act.sa_flags = 0;
//    sigemptyset(&act.sa_mask);
//
//    sigaction(SIGINT, &act, &oact);
//    while(1){
//        printf("I am a process!\n");
//        sleep(1);
//    }
//
//    return 0;
//}
