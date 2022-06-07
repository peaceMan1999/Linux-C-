#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pipefd[2] = { 0 };
    if (pipe(pipefd) > 0){
        perror("pipe");
        return 1;
    }
    
    pid_t id = fork();
    if (id == 0){
        close(pipefd[0]);
        // child
        //printf("%d\n", pipefd[0]);
        //printf("%d\n", pipefd[1]);
        const char *msg = "hello my father, I am your child";
        int count = 10;
        while (count){
            write(pipefd[1], msg, strlen(msg));
            sleep(1);
            count--;
        }
        close(pipefd[1]);
        exit(0);
    }

    close(pipefd[1]);
    // father
    int status = 0;
    char buff[64];
    while (1){
        ssize_t s = read(pipefd[0], buff, sizeof(buff));
        if (s > 0){
            buff[s] = '\0';
            printf("father get : %s\n", buff);
        }
        else if (s == 0){
            printf("read end\n");
            break;
        }
        else{
            printf("err\n");
            break;
        }
    }
    //waitpid(id, NULL, 0);
    waitpid(id, &status, 0); 
    printf("sign : %d\n", status & 0x7F);

    return 0;
}
