#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <malloc.h>

void *Routine(void *arg)
{
    int count = 0;
    char *msg = (char*)arg;
    while(count < 5){
        printf("%s : pid : %d ,ppid : %d\n", msg, getpid(), getppid());
        sleep(1);
        count++;
    }  
    //pthread_exit(0);
    pthread_detach(pthread_self());
}

int main()
{
    pthread_t tid[5];
    for(int i = 0; i < 5; i++){
        char *msg =(char*) malloc(64);
        sprintf(msg, "thread[%d]", i);
        pthread_create(&tid[i], NULL, Routine, (void*)msg);
    }
    
     printf("pid : %d ,ppid : %d, tid : %lu\n", getpid(), getppid(), pthread_self());
   // for (int i = 0; i < 5; i++){
   //     pthread_join(tid[i], NULL);

   //     printf("%d : %lu...quit\n", i, tid[i]);
   // }
    while (1){
        ;
    }
    return 0;
}
