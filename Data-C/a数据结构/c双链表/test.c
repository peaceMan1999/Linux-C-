#include "SeqList.h"

int main()
{
  NodeList* seq = Init();

  PushFront(seq, 1);
  PushFront(seq, 2);
  PushFront(seq, 3);
  Print(seq);

  PushBack(seq, 4);
  PushBack(seq, 5);
  PushBack(seq, 6);
  Print(seq);

  Size(seq);
  Emply(seq);

  PopFront(seq);
  PopFront(seq);
  Print(seq);

  PopBack(seq);
  PopBack(seq);
  Print(seq);

  Delete(seq);
  Emply(seq);
  Print(seq);

  return 0;
}



