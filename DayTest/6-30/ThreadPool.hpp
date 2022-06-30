#pragma once

#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <queue>
#include <ctime>
#include <stdlib.h>

#define NUM 5

template <typename T>

class ThreadPool{
    public:
        void Lock()
        {
            pthread_mutex_lock(&lock);
        }
        void Unlock()
        {
            pthread_mutex_unlock(&lock);
        }
        bool IsEmpty()
        {
            return q.size() == 0 ? true : false;
        }
        void Wait()
        {
            pthread_cond_wait(&wait, &lock);
        }
        void Signal()
        {
            pthread_cond_signal(&wait);
        }

        ThreadPool(int num = NUM)
            :_num(num)
        {
            pthread_mutex_init(&lock, nullptr); 
            pthread_cond_init(&wait, nullptr);
        }
        static void  *Routine(void *arg)
        {
            pthread_detach(pthread_self());
            ThreadPool *p = (ThreadPool*) arg;
            while (true){
                p->Lock();
                while (p->IsEmpty()){
                    // wait
                    p->Wait();
                }
                // 有任务
                T t;
                p->Pop(t);
                p->Unlock();
                
                // 处理任务
                //
                t.Run();
            }
        }
        void InitPool()
        {
            pthread_t tid;
            for (int i = 0; i < _num; i++){
               pthread_create(&tid, nullptr, Routine, this);
            }
        }
        void Push(const T& in)
        {
            Lock();
            q.push(in);
            Unlock();
            Signal(); 
        }
        void Pop(T& out)
        {
            out = q.front();
            q.pop();
        }
        ~ThreadPool()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&wait);
        }
    private:
        int _num;
        std::queue<T> q;
        pthread_mutex_t lock;
        pthread_cond_t wait;

};

