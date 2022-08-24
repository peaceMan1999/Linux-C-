#include "SeqList.h"

int main()
{
  NodeList* seq = NULL;
  Print(seq);

  PushFront(&seq, 1);
  PushFront(&seq, 2);
  PushFront(&seq, 3);
  PushFront(&seq, 4);
  Print(seq);

  PushBack(&seq, 5);
  PushBack(&seq, 6);
  Print(seq);

  PopFront(&seq);
  PopFront(&seq);
  Print(seq);

  PopBack(&seq);
  PopBack(&seq);
  Print(seq);
  
  PosPush(&seq, 2, 7);
  PosPush(&seq, 2, 8);
  PosPush(&seq, 2, 9);
  Print(seq);

  PosPop(&seq, 1);
  PosPop(&seq, 9);
  Print(seq);

  return 0;
}
