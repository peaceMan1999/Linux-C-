#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char* argv[], char* envp[])
{
    int g_val = 100;
    // 进程空间地址
    pid_t id = fork();
    if (id == 0){
        // child
        g_val = 200;
        printf("%d  %d  %d  %p\n", getpid(), getppid(), g_val, &g_val);
        sleep(1);
    }
    else if (id > 0){
       // parent
        printf("%d  %d  %d  %p\n", getpid(), getppid(), g_val, &g_val);
        sleep(1);
    }
    sleep(1);

    // 环境变量
    
    // 3/
    //printf("%s\n ",getenv("MYVAL"));
    

    // 2/
    //int i = 0;
    //extern char** environ;
    //while (environ[i])
    //{
    //    printf("environ[%d] : %s\n", i, environ[i]);
    //    i++;
    //}

    // 1/
    //int i = 0;
    //while (envp[i]){
    //    printf("envp[%d] : %s\n", i, envp[i]);
    //    i++;
    //}

    // 命令行参数
    //if (argc == 2)
    //{
    //    if (strcmp(argv[1], "-a") == 0){
    //        printf("-a -a\n");
    //    }
    //    else if (strcmp(argv[1], "-b") == 0){
    //        printf("-b -b\n");
    //    }
    //    else{
    //        printf("is else\n");
    //    }
    //}
    //else{
    //    printf("no no\n");
    //}
     
    //while (1)
    //{
    //    printf("I am going, pid : %d\n", getpid());
    //    sleep(1);
    //}
    return 0;
}
