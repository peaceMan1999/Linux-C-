#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

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
        cmd[0] = strtok(name, " ");
        int i = 1;
        while (cmd[i]= strtok(NULL, " ")){
            i++;
        }
        pid_t id = fork();
        if (id == 0){
            execvp("ls", cmd);
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
