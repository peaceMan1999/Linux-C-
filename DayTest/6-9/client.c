#include "shm.h"

int main()
{ 
    key_t k = ftok(PATHNAME, PROJ_ID);
    if(k < 0){
        perror("err");
        return 1;
    }

    printf("%x\n", k);
    int shmid = shmget(k, SIZE, IPC_CREAT);
    if(shmid < 0){
        perror("err");
        return 2;
    }

    char *men = shmat(shmid, NULL, 0);

    int i = 0;
    while(1){
        men[i] = 'A' + i;
        sleep(1);
        i++;
        men[i] = '\0';
        
    }
    
    shmdt(men);

    return 0;
}
