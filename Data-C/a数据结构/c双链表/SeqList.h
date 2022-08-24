#pragma once 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int T;

typedef struct NodeList{
  struct NodeList* prev;
  struct NodeList* next;
  T data;
}NodeList;

// 初始化--给一个头节点
NodeList* Init();

// 头插尾插
void PushFront(NodeList* seq, T x);
void PushBack(NodeList* seq, T x);

// 头删尾删
void PopFront(NodeList* seq);
void PopBack(NodeList* seq);

// 查找
NodeList* Find(NodeList* seq, T x);

// 大小
void Size(NodeList* seq);

// 判空
void Emply(NodeList* seq);

// 清空
void Delete(NodeList* seq);

// 打印
void Print(NodeList* seq);






