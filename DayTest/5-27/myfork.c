#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//int g_val = 100;
//int g_val2;

int main()
{
    pid_t id = fork();
    if (id == 0){
        printf("child do something! pid : %d \n", getpid());
        //int f = 1/0;
        exit(11);        

        //while (count > 0){
        //    printf("child do something! pid : %d \n", getpid());
        //    count--;
        //    return 1;
        //sleep(1);
        //int e = 1/0;
        //exit(2);
        //
        //}
    }
    else{
        int status = 0;
        //pid_t i = wait(&status);
        pid_t ret = waitpid(id, &status, 0);
        if (ret >= 0){
            printf("parent running! pid : %d\n",getpid());
            //printf("child exit code : %d\n", (status >> 8)&0xFF);
            //printf("child get signal : %d\n", status & 0x7F);
            if (WIFEXITED(status)){
                printf("%d\n", WEXITSTATUS(status));
            }
        }
    }



    //printf("begin!\n");
    //pid_t id = fork();
    //if (id == 0){
    //    //child
    //    printf("child do something");
    //    sleep(1);
    //    exit(3);
    //    //_exit(3);
    //}
    //printf("get child\n");
    //sleep(2);


    //for (int i = 0; i < 160; i++)
    //{
    //    printf("[%d] : %s\n", i, strerror(i));
    //}

    //exit(3);


    //printf("代码区 ：%p\n", main);
    //char* arr = "abcdef";
    //printf("字符常量区 ：%p\n", arr);
    //printf("定义全局变量 ：%p\n", &g_val);
    //printf("未定义全局变量 ：%p\n", &g_val2);
    //int* d = (int*)malloc(sizeof(int)*10);
    //printf("堆区 ：%p\n", d);
    //printf("栈区 ：%p\n", &arr);

    return 0;
}
