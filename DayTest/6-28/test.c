#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define TICKETS 10000

int tickets = TICKETS;

pthread_mutex_t lock;

void *GrabTickets(void *arg)
{
    int num = (int)arg;
    while(1){
        // 加锁
        pthread_mutex_lock(&lock);
        if (tickets > 0){
            usleep(100); 
            printf("[%d] : %d\n", num, tickets--);
            // 解锁
            pthread_mutex_unlock(&lock);
        }else{
            printf("[%d] : 已抢完\n", num);
            // 解锁
            pthread_mutex_unlock(&lock);
            break;
        }
    }
    return 0;
}

int main()
{
    pthread_t tid[5];
   
    // 设置锁
    pthread_mutex_init(&lock, NULL);
    int i = 0;
    for (; i < 5; i++)
    {
        //pthread_mutex_lock(&lock);
        pthread_create(&tid[i], NULL, GrabTickets, (void*)i ); 
        //pthread_mutex_unlock(&lock);
    }

    i = 0;
    for (; i < 5; i++)
    {
        pthread_join(tid[i], NULL);
    }

    // 关闭锁, 要放到等待线程后
    pthread_mutex_destroy(&lock);
    return 0;
}
