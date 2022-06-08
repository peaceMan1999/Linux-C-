#include "fifo.h"
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    if (mkfifo(FILE_NAME, 0644) < 0){
        perror("err");
        return 1;
    }

    int fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0){
        perror("open err");
        return 2;
    }
    
    int out = open("file-copy.txt", O_WRONLY|O_CREAT, 0644);

    char msg[64];
    while (1){
        msg[0] = 0;
        ssize_t s = read(fd, msg, sizeof(msg)-1);
        if (s > 0){
            write(out, msg, s);
           // msg[s] = 0;
           // printf("client## %s\n", msg);
           // int flag = 0;
           // const char *cmd = "+-*/";
           // char *p = msg;
           // while(*p){
           //     switch(*p){
           //         case '+':
           //             flag = 0;
           //             break;
           //         case '-':
           //             flag = 1;
           //             break;
           //         case '*':
           //             flag = 2;
           //             break;
           //         case '/':
           //             flag = 3;
           //             break;
           //     }
           //     p++;
           // }
           // char *leftstr = strtok(msg, "+-*/");
           // char *rightstr = strtok(NULL, "+-*/");
           // int left = atoi(leftstr);
           // int right = atoi(rightstr);
           // int x = 0;
           // switch(flag){
           //     case 0:
           //         x = left + right;
           //         break;
           //     case 1:
           //         x = left - right;
           //         break;
           //     case 2:
           //         x = left * right;
           //         break;
           //     case 3:
           //         x = left / right;
           //         break;
           // }
           // printf("%d %c %d = %d\n", left, cmd[flag], right, x);
           // msg[s] = 0;
           // if (fork() == 0){
           //     execlp(msg, msg, NULL);
           //     exit(1);
           // }
           // waitpid(-1, NULL, 0);
        } 
        else if (s == 0){
            printf("read end\n");
            break;
        }
        else{
            perror("read err");
            break;
        }

    }
    close(fd);
    close(out);

    return 0;
}
