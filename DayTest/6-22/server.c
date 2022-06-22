#include "comm.h"

int main()
{
    key_t key = ftok(FILENAME, PROJ_ID); 
    if (key < 0){
        perror("ftok error\n");
        return 1;
    }
    
    //sleep(5);

    int shm = shmget(key, SIZE, IPC_CREAT|IPC_EXCL|0666);
    if (shm < 0){
        perror("shm error\n");
        return 2;
    }
   
    //sleep(5);
   
    char *mem = shmat(shm, NULL, 0);
    
    while(1){
        printf("client say : %s\n", mem);
        sleep(1);
    }
    
    shmdt(mem);
    shmctl(shm, IPC_RMID, NULL);

    return 0;
}
