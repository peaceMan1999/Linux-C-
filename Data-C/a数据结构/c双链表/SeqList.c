#include "SeqList.h"


// 创建
static NodeList* Found(T x)
{
  NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
  if (newNode == NULL){
    perror("Found");
    exit(-1);
  }
  newNode->data = x;
  newNode->next = newNode->prev = NULL;
  return newNode;
}

// 初始化
NodeList* Init()
{
  NodeList* newNode = Found(0);
  newNode->next = newNode;
  newNode->prev = newNode;
  return newNode;
}

// 头插尾插
void PushFront(NodeList* pNode, T x)
{
  NodeList* newNode = Found(x);
  pNode->next->prev = newNode;
  newNode->next = pNode->next;
  pNode->next = newNode;
  newNode->prev = pNode;
}

void PushBack(NodeList* pNode, T x)
{
  NodeList* newNode = Found(x);
  pNode->prev->next = newNode;
  newNode->prev = pNode->prev;
  pNode->prev = newNode;
  newNode->next = pNode;
}

// 头删尾删
void PopFront(NodeList* pNode)
{
  NodeList* cur = pNode->next;
  pNode->next = cur->next;
  cur->next->prev = pNode;
  free(cur);
  cur = NULL;
}
void PopBack(NodeList* pNode)
{
  NodeList* prev = pNode->prev;
  prev->prev->next = prev->next;
  pNode->prev = prev->prev;
  free(prev);
  prev = NULL;
}

// 查找
NodeList* Find(NodeList* pNode, T x)
{
  assert(pNode);
  NodeList* cur = pNode->next;
  while (cur != pNode)
  {
    if (cur->data == x){
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}


// 大小
void Size(NodeList* pNode)
{
  assert(pNode);
  int size = 0;
  NodeList* cur = pNode->next;
  while (cur != pNode)
  {
    size++;
    cur = cur->next;
  }
  printf("%d\n", size);
}

// 判空
void Emply(NodeList* pNode)
{
  assert(pNode);
  if (pNode->next == pNode){
    printf("空\n");
  }else{
    printf("非空\n");
  }
}

// 清空
void Delete(NodeList* pNode)
{
  assert(pNode);
  NodeList* cur = pNode->next;
  while (cur != pNode)
  {
    NodeList* Next = cur->next;
    free(cur);
    cur = Next;
    Next = Next->next;
  }
  pNode->next = pNode;
  pNode->prev = pNode;
}

// 打印
void Print(NodeList* pNode)
{
  assert(pNode);
  NodeList* cur = pNode->next;
  while (cur != pNode)
  {
    printf("%d -> ", cur->data);
    cur = cur->next;
  }
  printf("NULL\n");
}
















