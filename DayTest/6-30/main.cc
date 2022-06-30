#include "ThreadPool.hpp"
#include "task.hpp"
int main()
{
    ThreadPool<Task> *q = new ThreadPool<Task>();
    q->InitPool();
   
    srand((unsigned long)time(nullptr));

    const char *op = "+-*/";
    while (true){
        int x = rand()%100+1;
        int y = rand()%50;
        char ch = op[rand()%4];

        Task t(x, y, ch);
        q->Push(t);

        sleep(1);
    }

    return 0;
}
