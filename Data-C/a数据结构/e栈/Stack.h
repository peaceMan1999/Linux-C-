#pragma once 
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef int T;

typedef struct Stack{
  T* _arr;
  int _size;
  int _capacity;
}Stack;

// 初始化
void Init(Stack* st);

// 加入
void Push(Stack* st, T x);

// 删除
void Pop(Stack* st);

// 判空
void Empty(Stack* st);

// 栈顶
void Top(Stack* st);

// 大小
void Size(Stack* st);

// 清空
void Delete(Stack* st);

// 打印
void Print(Stack* st);


