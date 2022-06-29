#pragma once

#include <iostream>
#include <queue>
#include <unistd.h>
#include <pthread.h>
#include <ctime>
#include <stdlib.h>

#define NUM 32

template <typename T>

class BlockQueue{
    private:
        bool IsFull()
        {
            return q.size() == _capcity;
        }
        bool IsEmpty()
        {
            return q.empty();
        }
    public:
        BlockQueue(int capcity = NUM)
            :_capcity(capcity)
        {
            pthread_mutex_init(&lock, nullptr);
            pthread_cond_init(&full, nullptr);
            pthread_cond_init(&empty, nullptr);
        }
        
        void Push(const T& in){
            pthread_mutex_lock(&lock);
            while (IsFull()){
                pthread_cond_wait(&full, &lock);
            }
            q.push(in);
            if (q.size() >= _capcity/2){
               // std::cout << "消费者快来消费" << std::endl;
                pthread_cond_signal(&empty);
            }
            pthread_mutex_unlock(&lock);
        }
        
        void Pop(T& out){
            pthread_mutex_lock(&lock);
            while (IsEmpty()){
                pthread_cond_wait(&empty, &lock);
            }
            out = q.front();
            q.pop();
            if (q.size() < _capcity/2){
               // std::cout << "厂家快生产" << std::endl;
                pthread_cond_signal(&full);
            }
            pthread_mutex_unlock(&lock);
        }

        ~BlockQueue()
        {
            pthread_mutex_destroy(&lock);

            pthread_cond_destroy(&full);
            pthread_cond_destroy(&empty);
        }

    private:
        std::queue<T> q;
        int _capcity;
        pthread_mutex_t lock;
        pthread_cond_t full;
        pthread_cond_t empty;
};
