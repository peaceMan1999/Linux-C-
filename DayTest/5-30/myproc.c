#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("begin\n");
    pid_t id = fork();
    if (id == 0){
        sleep(1);
        char* myenvp[] = {"MYVAL=YOU CAN SEE ME"};
        
        execle("./test","test", NULL, myenvp);

        printf("exec error\n");
    }
    
    int status = 0;
    pid_t ret = waitpid(id, &status, 0);
    if (ret >= 0){
        printf("exit code : %d\n",WEXITSTATUS(status));
    }


    //printf("begin\n");
    //sleep(1);
    //execl("bin/bash/ls", "ls", "-a", "-i", "-o", NULL);
    //错误的信息不会进行替换
    
    //execl("/usr/bin/ls", "ls", "-a", "-i", "-o", NULL);
    
    //char* myarg[] = {"ls", "-a", "-i", "-o", NULL};
    //execv("/usr/bin/ls", myarg);

    //execlp("ls", "ls", "-a", "-i", "-o", NULL);

    //execvp("ls", myarg);
    
    //char* myenvp[] = {"MYVAL=YOU CAN SEE ME"};
    //execle("/usr/bin/ls", "ls", myenvp);

    //printf("execl error\n");

    return 0;
}
