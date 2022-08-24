#include "SeqList.h"

int main()
{
  SeqList seq;
  Init(&seq);

  PushFront(&seq, 1);
  PushFront(&seq, 2);
  PushFront(&seq, 3);
  PushFront(&seq, 4);
  PushFront(&seq, 5);
  Print(&seq);
  // 54321
  PushBack(&seq, 7);
  PushBack(&seq, 8);
  Print(&seq);
  // 5432178

  PopFront(&seq);
  PopFront(&seq);
  PopFront(&seq);
  Print(&seq);
  // 2178
  
  PopBack(&seq);
  PopBack(&seq);
  Print(&seq);
  // 21
  
  return 0;
}
