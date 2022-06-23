#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>


//void handler(int signo){
//    printf("got a signo : %d\n", signo);
//    // signal(signo, handler);
//}

int main()
{
   // int i = 1;
   // for (; i < 32; i++){
   //     signal(i, handler);
   // }
    if (fork() == 0){
        sleep(2);
        int *p = NULL;
        *p = 100;
        //int i = 1/0;
        exit(0);
    }

    int status = 0;

    waitpid(-1, &status, 0);

    printf("exit : %d, core dump : %d, signo : %d\n", (status >> 8)&0xff, (status>>7)& 0x01, status & 0x7f);

    //while (1){
        //printf("hello\n");
        //sleep(5);
        ////int i = 1/0;
        //int *p = NULL;
        //*p = 100;
    //} 

    return 0;
}
