#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *Routine(void *arg)
{
    char *msg = (char*)arg;
    while(1){
        printf("%s\n", msg);
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, Routine, (void*)"thread 1");

    while(1){
        printf("I am main yhread!\n");
        sleep(2);
    }

    return 0;
}
