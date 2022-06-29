#include "PCModel.hpp"
#include "task.hpp"

void *Consumer(void *arg)
{
    auto bq = (BlockQueue<Task>*)arg;
    while (true){
        sleep(1);
        Task t;
        bq->Pop(t);
        t.Run();
        std::cout << "计算" << std::endl;
    }
}

void *Producers(void *arg)
{
    auto bq = (BlockQueue<Task>*)arg;
    const char *p = "+-*/";
    while (true){
        //sleep(3);
        int x = rand()%100+1;
        int y = rand()%50;
        char op = p[rand()%4];
        Task t(x, y, op);
        
        bq->Push(t);
    }
}


int main()
{
    srand((unsigned long)time(nullptr));

    BlockQueue<Task> *bq = new BlockQueue<Task>();

    pthread_t t1, t2;
    
    pthread_create(&t1, NULL, Consumer, bq);
    pthread_create(&t2, NULL, Producers, bq);
    
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    return 0;
}
