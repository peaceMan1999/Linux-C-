#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;

typedef struct SList
{
  struct SList* next;
  SLDataType data;
}SList;

//头增
extern void push_back(SList** ps, SLDataType data);
extern void pop_back(SList** ps);
//尾增删
extern void push_front(SList** ps, SLDataType data);
extern void pop_front(SList** ps);
//查改
extern SList* find(SList* ps, SLDataType data);
extern void revise(SList* ps, SLDataType data);
//插入删除
extern void insert(SList** ps, SList* pos, SLDataType data);
extern void erase(SList** ps, SList* pos);
//打印
extern void print(SList* ps);
//析构
extern void destroy(SList* ps);


