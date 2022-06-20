#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int fd[2] = { 0 };
    if (pipe(fd) < 0){
        perror("pipe!");
        return 1;
    }

    // 创建进程
    pid_t id  = fork();
    if (id == 0){
        // child
        close(fd[0]);
        const char *buff = "hello father, i am child";
        int count = 0;
        char c = 'a';
        while(1){
            write(fd[1], &c, 1);
            count++;
            printf("%d\n", count);
        }
      //  int count = 5;
      //  while (count){
      //      write(fd[1], buff, strlen(buff));
      //      count--;
      //     // sleep(1);
      //  }
        close(fd[1]);
        exit(0);
    }

    // father
    close(fd[1]);
    //close(fd[0]);
    char buff[64];
    while(1){
        ssize_t s = read(fd[0], buff, sizeof(buff));
        if (s > 0){
            buff[s] = '\0';
            printf("n: %s", buff);
        }
       // if (s > 0){
       //     buff[s] = '\0';
       //     printf("child say : %s\n", buff);
       // }
       // else if (s == 0){
       //     printf("child end!\n");
       //     break;
       // }
       // else{
       //     printf("error\n");
       //     break;
       // }
    }
    waitpid(id, NULL, 0);
    //int status = 0;
    //waitpid(id, &status, 0);
    //printf("end! %d\n", status & 0x7F);
    return 0;
}
