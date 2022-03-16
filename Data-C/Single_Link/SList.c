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
extern void find();
extern void revise();
//插入删除
extern void insert();
extern void erase();
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


