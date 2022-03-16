#include "SList.h"

void f1()
{
  SList* s = NULL;
  push_back(&s, 1);
  push_back(&s, 2);
  push_back(&s, 3);
  push_front(&s, 4);
  push_front(&s, 5);
  print(s);
  
  pop_back(&s);
  pop_back(&s);
  pop_back(&s);
  pop_back(&s);
  pop_back(&s);
  pop_back(&s);
  pop_front(&s);
  print(s);
  destroy(s);
}

int main()
{
  f1();

  return 0;
}

