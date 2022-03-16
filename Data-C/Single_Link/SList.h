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
extern void find();
extern void revise();
//插入删除
extern void insert();
extern void erase();
//打印
extern void print(SList* ps);
//析构
extern void destroy(SList* ps);


