#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#define NUM 1000
#define LEN 32

int main()
{
    char name[NUM];
    char* cmd[LEN];
    while(1){
        printf("[yz@VM-20-9-centos shell]# ");
        fgets(name, NUM, stdin); 
        name[strlen(name)-1] = '\0';
       
        char *start = name;
        while (*start != '\0'){
            if (*start == '>'){
                *start = '\0';
                start++;
                break;
            }

            start++;
        }
        if (*start != '\0'){
            while (isspace(*start)){
                start++;
            }
        }
        else{
            start = NULL;
        }
        
        cmd[0] = strtok(name, " ");
        int i = 1;
        while (cmd[i]= strtok(NULL, " ")){
            i++;
        }
        pid_t id = fork();
        if (id == 0){
            if (start != NULL){
                int fd = open(start, O_WRONLY|O_CREAT, 0644);
                if (fd < 0){
                    perror("err");
                    exit(1);
                }
                dup2(fd, 1);
            }
            execvp(cmd[0], cmd);
            exit(0);
        }
        
        int status = 0;
        pid_t ret = waitpid(id, &status, 0);
        if (ret >= 0){
            printf("exit code : %d\n", WEXITSTATUS(status));
        }else{
            printf("error\n");
        }
    }

    return 0;
}
