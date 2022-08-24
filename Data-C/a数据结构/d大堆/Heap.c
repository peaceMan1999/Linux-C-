#include "Heap.h"

void Swap(T* a, T* b)
{
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

// 建堆
static void AdjustDown(Heap* hp, int k, int parent)
{
  int child = parent*2 + 1;
  
  while (child < k) // child <= k-1
  {
    if (child < k - 1 && hp->_arr[child+1] > hp->_arr[child])
    {
      child++;
    }
    if (hp->_arr[child] > hp->_arr[parent])
    {
      Swap(&hp->_arr[child], &hp->_arr[parent]);
      parent = child;
      child = parent*2 + 1;
    }
    else
    {
      break;
    }
  }
}

// 初始化
void Init(Heap* hp, T* a, int k)
{
  hp->_arr = (T*)malloc(sizeof(T) * k);
  if (hp->_arr == NULL){
    perror("Init");
    exit(-1);
  }
  memcpy(hp->_arr, a, sizeof(T)*k);
  hp->_size = hp->_capacity = k;

  // 建堆
  int i = (k-1-1)/2; 
  for (; i >= 0; i--)
  {
    AdjustDown(hp, k, i);
  }


}

// 插入
void Push(Heap* hp, T x)
{
  assert(hp);

  if (hp->_size == hp->_capacity)
  {
    hp->_arr = (T*)realloc(hp->_arr, sizeof(T)*hp->_capacity*2);
    if (hp->_arr == NULL){
      perror("Push new");
      exit(-1);
    }
  }
  hp->_arr[hp->_size] = x;
  hp->_size++;

  int i = (hp->_size-1-1)/2;
  for (; i >= 0; i--)
  {
    AdjustDown(hp, hp->_size, i);
  }
}

// 删除
void Pop(Heap* hp)
{
  assert(hp);
  assert(hp->_size);
  
  Swap(&hp->_arr[0], &hp->_arr[hp->_size-1]);
  hp->_size--;

  int i = (hp->_size-1-1)/2;
  for (; i >= 0; i--)
  {
    AdjustDown(hp, hp->_size, i);
  }

}

// 堆顶
void Top(Heap* hp)
{
  assert(hp);
  printf("%d\n", hp->_arr[0]);
}

// 判空
void Emply(Heap* hp)
{
  if (hp->_size == 0){
    printf("空\n");
  }else{
    printf("非空\n");
  }
}

// 大小
void Size(Heap* hp)
{
  printf("%d\n", hp->_size);
}

// 打印
void Print(Heap* hp)
{
  assert(hp);

  printf("数组:");
  int i = 0;
  for (; i < hp->_size; i++)
  {
    printf("%d ", hp->_arr[i]);
  }
  printf("\n");

  printf("堆: \n");
  i = 0;
  int j = 0, k = 1, n = 6, count = 0;
  for (i = 0; i < n; i++)
  {
    if (count >= hp->_size)
      break;
    for (j = hp->_size-k; j > 0; j--)
    {
      printf(" ");
    }
    for (j = 0; j < k; j++)
    {
      printf("%d ", hp->_arr[count]);
      count++;
      if (count >= hp->_size)
        break;
    }
    k *= 2;
    printf("\n\n");
  }
}

// 销毁
void Delete(Heap* hp);







