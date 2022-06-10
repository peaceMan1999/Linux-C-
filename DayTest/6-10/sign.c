#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

void handler(int signo)
{
    printf("get signo : %d\n", signo);
    signal(signo, handler);
}

int main()
{
    int id = fork();
    if (id == 0){
        printf("child\n");
        int x = 1/0;
        exit(0);
    }

    int status = 0;
    waitpid(-1, &status, 0);
    printf("%d %d %d\n", (status>>8)&0xff, (status>>7)&1, status&0x7f);

   // for(int signo = 1; signo < 32; signo++){
   //     signal(signo, handler);
   // }
   // 
   // while (1){
   //     sleep(1);
   // }
   // while (1){
   //     printf("hello\n");
   //     sleep(1);
   //     int *p = NULL;
   //     *p = 100;
   // }

    return 0;
}
