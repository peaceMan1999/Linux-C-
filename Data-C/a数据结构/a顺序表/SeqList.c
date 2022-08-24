#include "SeqList.h"


extern void Found(SeqList* seq);

// 头插头删
void PushFront(SeqList* seq, T x)
{
  assert(seq);

  Found(seq);

  int ret = seq->size-1;
  while (ret >= 0)
  {
    seq->data[ret+1] = seq->data[ret];
    ret--;
  }
  
  seq->data[0] = x;
  seq->size++;
}

void PopFront(SeqList* seq)
{
  assert(seq);

  int ret = 0;
  if (seq->size == 0)
  {
    return;
  }
  while (ret < seq->size-1)
  {
    seq->data[ret] = seq->data[ret+1];
    ret++;
  }
  seq->size--;
}

// 尾插尾删
void PushBack(SeqList* seq, T x)
{
  assert(seq);
  Found(seq);

  seq->data[seq->size] = x;
  seq->size++;
}

void PopBack(SeqList* seq)
{
  assert(seq);
  if(seq->size == 0)
    return;

  seq->size--;
}

// 初始化、销毁、扩容


void Init(SeqList* seq)
{
  assert(seq);
  seq->size = seq->capacity = 0;
  seq->data = NULL;

  Found(seq);
}

void Delete(SeqList* seq)
{
  assert(seq);
  
  free(seq->data);
  seq->data = NULL;
  seq->capacity = seq->size = 0;
}

void Found(SeqList* seq)
{

  if (seq->size == seq->capacity)
  {
    int _size = seq->capacity == 0 ? 4 : seq->capacity * 2;
    
    T* newT = (T*)realloc(seq->data, _size * sizeof(T));
    
    if (newT == NULL)
    {
      perror("Found");
      exit(-1);
    }

    seq->data = newT;
    seq->capacity = _size;
  }

}

// 打印
void Print(SeqList* seq)
{
  for (int i = 0; i < seq->size; i++)
  {
    printf("%d ", seq->data[i]);
  }
  printf("\n");
}



