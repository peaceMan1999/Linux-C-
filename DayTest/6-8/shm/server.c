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
    int shm = shmget(k, SIZE, IPC_CREAT|IPC_EXCL);
    if(shm < 0){
        perror("err");
        return 2;
    }
   
    sleep(10);

    shmctl(shm, IPC_RMID, NULL);
    
    sleep(10);
    return 0;
}
