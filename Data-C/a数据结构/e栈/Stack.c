#include "Stack.h"

static void Found(Stack* st)
{
  if (st->_capacity == st->_size)
  {
    st->_arr = (T*)realloc(st->_arr, sizeof(T)*st->_capacity * 2);
  }
}

// 初始化
void Init(Stack* st)
{
  st->_arr = (T*)malloc(sizeof(T)*4);
  st->_size = 0;
  st->_capacity = 4;
}

// 加入
void Push(Stack* st, T x)
{
  if (st->_capacity == st->_size){
    Found(st);
  }
  st->_arr[st->_size] = x;
  st->_size++;
}

// 删除
void Pop(Stack* st)
{
  assert(st);

  st->_size--;
}

// 判空
void Empty(Stack* st)
{
  if (st->_size == 0)
    printf("空\n");
  else
    printf("非空\n");
}

// 栈顶
void Top(Stack* st)
{
  assert(st);

  printf("Top : %d\n", st->_arr[st->_size-1]);
}

// 大小
void Size(Stack* st)
{
  printf("Size : %d\n", st->_size);
}

// 清空
void Delete(Stack* st)
{
  assert(st);

  st->_size = 0;
}

// 打印
void Print(Stack* st)
{
  if (st->_size == 0)
  {
    printf("NULL\n");
  }
  else
  {
    printf("栈: ");
    int i = 0;
    for (; i < st->_size; i++)
    {
      printf("%d ", st->_arr[i]);
    }
    printf("\n");
  }
}



