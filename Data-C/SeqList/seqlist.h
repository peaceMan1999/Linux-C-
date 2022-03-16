#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

typedef struct Seqlist
{
  SLDataType* data;
  size_t sz;
  size_t capacity;
}Seqlist;


//尾插
extern void push_back(Seqlist* ps, SLDataType val);
//头插
extern void push_front(Seqlist* ps, SLDataType val);
//尾删
extern void pop_back(Seqlist* ps);
//头删
extern void pop_front(Seqlist* ps);
//打印
extern void print(Seqlist* ps);
//初始化
extern void Init(Seqlist* ps);
//销毁
extern void Destroy(Seqlist* ps);
//创建
extern void New(Seqlist* ps);


