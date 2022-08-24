#pragma once 
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


typedef int T;

typedef struct QueueNode{
    T data;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue{
    QueueNode* head;
    QueueNode* tail;
}Queue;

// 初始化
void Init(Queue* que);

// 插入
void Push(Queue* que, T x);

// 删除
void Pop(Queue* que);

// 队前、队后
void QueueFront(Queue* que);
void QueueBack(Queue* que);

// 大小
void Size(Queue* que);

// 判空
void Emply(Queue* que);

// 清空
void Delete(Queue* que);

// 打印
void Print(Queue* que);










