#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("let begin!\n"); // 由父进程执行
    // 僵尸进程和孤儿进程
    pid_t id = fork();
    if (id > 0){
        int count = 5;
        while (count--)
        {
            printf("father pid : %d, ppid : %d\n",getpid(), getppid());
            sleep(2);
        }
        printf("father quit\n");
    }
    else if (id == 0)
    {
        while (1)
        {
            printf("child pid : %d, ppid : %d\n",getpid(), getppid());
            sleep(1);
        }
    }
    return 0;

//    while(1)
//    {
//
//    }
    //pid_t id = fork();
    //while (1)
    //{
    //    if (id == 0){
    //        // child
    //        printf("i am child -- pid : %d, ppid : %d\n", getpid(), getppid());
    //        sleep(1);
    //    }
    //    else if (id > 0){
    //        // parent
    //        printf("i am father -- pid : %d, ppid : %d\n", getpid(), getppid());
    //        sleep(2);
    //    }
    //    else{
    //        //error
    //    }
    //}
    return 0;
}
