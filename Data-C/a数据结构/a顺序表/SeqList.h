#pragma once 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int T;

typedef struct SeqList{
  T* data;
  int size;
  int capacity;
}SeqList;


// 头插头删
void PushFront(SeqList* seq, T x);
void PopFront(SeqList* seq);

// 尾插尾删
void PushBack(SeqList* seq, T x);
void PopBack(SeqList* seq);

// 初始化、销毁、扩容
void Init(SeqList* seq);
void Delete(SeqList* seq);

// 打印
void Print(SeqList* seq);


