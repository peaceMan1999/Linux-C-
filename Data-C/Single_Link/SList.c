#include "SList.h"

static SList* buy(SLDataType data)
{
  SList* new = (SList*)malloc(sizeof(SList));
  if (new == NULL)
  {
    perror("error");
    return NULL;
  }
  new->data = data;
  new->next = NULL;

  return new;
}

//尾头增
void push_back(SList** ps, SLDataType data)
{
  SList* new = buy(data);

  if (*ps == NULL)
    *ps = new;
  else
  {
    SList* end = *ps;
    while(end->next != NULL)
    {
      end = end->next;
    }
    end->next = new;
  }
}

void pop_back(SList** ps)
{
  //没有
  if (*ps == NULL)
    return;
  //只有一个
  if ((*ps)->next == NULL)
  {
    free(*ps);
    *ps = NULL;
  }
  //多个
  else
  {
    SList* end = *ps;
    SList* front = NULL;
    while(end->next != NULL)
    {
      front = end;
      end = end->next;
    }
    free(end);
    end = NULL;
    front->next = NULL;
  }
}

//头尾删
void push_front(SList** ps, SLDataType data)
{
  SList* new = buy(data);
  new->next = *ps;
  *ps = new;
}

void pop_front(SList** ps)
{
  if (*ps != NULL)
  {
    SList* end = (*ps)->next;
    free(*ps);
    *ps = end;
  }
}

//查改
SList* find(SList* ps, SLDataType data)
{
  if (ps == NULL)
    return NULL;
  SList* end = ps;
  while (end != NULL)
  {
    if (end->data == data)
      return end;
    end = end->next;
  }
  return NULL;
}

void revise(SList* pos, SLDataType data)
{
  if (pos == NULL)
    return;
  pos->data = data;

}
//插入删除
void insert(SList** ps, SList* pos, SLDataType data)
{
  if (pos == NULL)
    return;
  SList* new = buy(data);
  //first
  if (pos == *ps)
  {
    new->next = *ps; 
    *ps = new;
  }
  //second
  else
  {
    SList* front = NULL;
    SList* end = *ps;
    while (end != pos)
    {
      front = end;
      end = end->next;
    }
    front->next = new;
    new->next = pos;
  }


}

void erase(SList** ps, SList* pos)
{
  if (pos == NULL)
    return;
  //first
  if (pos == *ps)
  {
    SList* end = (*ps)->next;
    free(*ps);
    *ps = end;
  }
  //second
  else
  {
    SList* front = NULL;
    SList* end = *ps;
    while (end != pos)
    {
      front = end;
      end = end->next;
    }
    front->next = pos->next;
    free(pos);
    pos = NULL;
  }
}

//打印
void print(SList* ps)
{
  SList* end = ps;
  while(end != NULL)
  {
    printf("%d->",end->data);
    end = end->next;
  }
  printf("NULL\n");
}
//析构
void destroy(SList* ps)
{
  while (ps != NULL)
  {
    SList* end = ps->next;
    free(ps);
    ps = end;
  }

}


