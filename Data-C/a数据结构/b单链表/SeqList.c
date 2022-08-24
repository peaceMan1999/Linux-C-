#include "SeqList.h"

static NodeList* Found(T x)
{
  NodeList* node = (NodeList*)malloc(sizeof(NodeList));
  if (node == NULL){
    perror("Found");
    exit(-1);
  }
  node->data = x;
  node->next = NULL;

  return node;
}

void PushFront(NodeList** ppNode, T x)
{
  NodeList* newNode = Found(x);

  newNode->next = *ppNode;
  *ppNode = newNode;
}

void PushBack(NodeList** ppNode, T x)
{
  NodeList* newNode = Found(x);
  
  if (*ppNode == NULL){
    *ppNode = newNode;
  }else{
    NodeList* end = *ppNode;
    while (end->next != NULL)
    {
      end = end->next;
    }
    end->next = newNode;
  }
}


// 头删尾删
void PopFront(NodeList** ppNode)
{
  if (*ppNode == NULL){
    return;
  }else{
    NodeList* cur = (*ppNode)->next;
    free(*ppNode);
    *ppNode = cur;
  }
}

void PopBack(NodeList** ppNode)
{
  if (*ppNode == NULL){
    return;
  }else if ((*ppNode)->next == NULL){
    free(*ppNode);
    *ppNode = NULL;
  }else{
    NodeList* end = *ppNode;
    NodeList* prev = NULL;
    while (end->next != NULL)
    {
      prev = end;
      end = end->next;
    }
    free(end);
    end = NULL;
    prev->next = NULL;
  }
}


// 查找、改
NodeList* Find(NodeList* pNode, T x)
{
  if (pNode == NULL){
    return NULL;
  }
  NodeList* cur = pNode;
  while (cur != NULL){
    if (cur->data == x)
    {
      return cur;
    }
    cur = cur->next;
  }
  printf("没有找到\n");
  return NULL;
}

void Revise(NodeList* pNode, T x)
{
  if (pNode == NULL){
    perror("无数据修改");
    exit(-1);
  }
  NodeList* cur = Find(pNode, x);
  cur->data = x;
}

// 位置插、位置删
void PosPush(NodeList** ppNode,T pos, T x)
{
  NodeList* cur = Find(*ppNode, pos);

  if (cur != NULL){
    NodeList* newNode = Found(x);
    newNode->next = cur->next;
    cur->next = newNode;
  }
}

void PosPop(NodeList** ppNode,T pos)
{
  NodeList* cur = Find(*ppNode, pos);
  
  if (cur == NULL){
    perror("无数据可删--位置删");
    exit(-1);
  }
  if (cur == *ppNode){
    NodeList* Next = (*ppNode)->next;
    free(*ppNode);
    *ppNode = Next;
  }else{
    NodeList* prev = *ppNode;
    while (prev != NULL && prev->next != cur)
    {
      prev = prev->next;
    }
    prev->next = cur->next;
    free(cur);
    cur = NULL;
  }
}

// 打印
void Print(NodeList* pNode)
{
  NodeList* cur = pNode;
  while (cur != NULL){
    printf("%d ", cur->data);
    cur = cur->next;
  }
  printf("\n");
}












