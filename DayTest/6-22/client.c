#include "comm.h"

int main()
{
    key_t key = ftok(FILENAME, PROJ_ID);

    int shm = shmget(key, SIZE, IPC_EXCL);

    char *mem = shmat(shm, NULL, 0);
    
    int i = 0;
    while (1){
        mem[i] = 'A'+i;
        i++;
        sleep(1);
    }

    shmdt(mem);

    return 0;
}
