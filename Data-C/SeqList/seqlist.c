#include "seqlist.h"

void Init(Seqlist* ps)
{
  assert(ps);

  ps->data = NULL;
  ps->sz = ps->capacity = 0;
}


void New(Seqlist* ps)
{
  assert(ps);
  if (ps->sz == ps->capacity)
  {
    int newcapacity = ps->capacity == 0 ? 4 :ps->capacity*2;
    SLDataType* tmp = (SLDataType*)realloc(ps->data, sizeof(SLDataType)*(newcapacity));
    if (tmp == NULL)
    {
      perror("new error");
      exit(-1);
    }
    ps->data = tmp;
    ps->capacity = newcapacity;
  }
  
}

void push_back(Seqlist* ps, SLDataType val)
{
  assert(ps);

  New(ps);

  ps->data[ps->sz] = val;
  ps->sz++;
}

void push_front(Seqlist* ps, SLDataType val)
{
  assert(ps);

  New(ps);

  for(int i = ps->sz; i >= 0; i--)
  {
    ps->data[i+1] = ps->data[i];
  }
  ps->data[0] = val;
  ps->sz++;
}

void pop_back(Seqlist* ps)
{
  assert(ps);
  
  if (ps->sz != 0)
     ps->sz--;
}

void pop_front(Seqlist* ps)
{
  assert(ps);
  if (ps->sz != 0)
  {
    for (int i = 0; i < ps->sz; i++)
    {
       ps->data[i] = ps->data[i+1];
    }
    ps->sz--;
  } 
}

void Destroy(Seqlist* ps)
{
  free(ps->data);
  ps->data = NULL;
  ps->sz = ps->capacity = 0;
}

void print(Seqlist* ps)
{
  assert(ps);
  
  for(int i = 0; i < ps->sz; i++)
  {
    printf("%d ", ps->data[i]);
  }
  printf("\n");

}





