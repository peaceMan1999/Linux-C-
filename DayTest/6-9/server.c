#include "shm.h"
#include <unistd.h>

int main()
{
    key_t k = ftok(PATHNAME, PROJ_ID);
    if(k < 0){
        perror("err");
        return 1;
    }

    printf("%x\n", k);
    int shmid = shmget(k, SIZE, IPC_CREAT|IPC_EXCL|0644);
    if(shmid < 0){
        perror("err");
        return 2;
    }
  
    char *men = shmat(shmid, NULL, 0);

    while(1){
        printf("client ## %s\n", men);
        sleep(1);
    }

   // printf("%x\n", men);

   // sleep(5);

   // shmdt(men);

   // sleep(5);

   // shmctl(shmid, IPC_RMID, NULL);
   // 
   // sleep(5);
    return 0;
}
