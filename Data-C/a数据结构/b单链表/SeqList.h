#pragma once 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int T;

typedef struct NodeList{
  T data;
  struct NodeList* next;
}NodeList;

// 头插尾插
void PushFront(NodeList** seq, T x);
void PushBack(NodeList** seq, T x);

// 头删尾删
void PopFront(NodeList** seq); 
void PopBack(NodeList** seq);

// 查找、改
NodeList* Find(NodeList* seq, T x);
void Revise(NodeList* seq, T x);

// 位置插、位置删
void PosPush(NodeList** seq,T pos, T x);
void PosPop(NodeList** seq,T pos);

// 打印
void Print(NodeList* seq);










