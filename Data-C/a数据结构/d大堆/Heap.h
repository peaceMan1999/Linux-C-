#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

typedef int T;

typedef struct Heap{
  T* _arr;
  int _size;
  int _capacity;
}Heap;

// 初始化
void Init(Heap* hp, T* a, int k);

// 插入
void Push(Heap* hp, T x);

// 删除
void Pop(Heap* hp);

// 堆顶
void Top(Heap* hp);

// 判空
void Emply(Heap* hp);

// 大小
void Size(Heap* hp);

// 打印
void Print(Heap* hp);

// 销毁
void Delete(Heap* hp);








