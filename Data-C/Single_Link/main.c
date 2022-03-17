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

void f2()
{
  SList* s = NULL;
  push_back(&s, 1);
  push_back(&s, 2);
  push_back(&s, 3);
  print(s);
  SList* pos = find(s, 2);
  revise(pos, 20);
  print(s);
}

void f3()
{
  SList* s = NULL;
  push_back(&s, 1);
  push_back(&s, 2);
  push_back(&s, 3);
  push_back(&s, 4);
  push_back(&s, 5);
  print(s);
  SList* pos = find(s, 4);
  insert(&s, pos, 10);
  insert(&s, pos, 20);
  print(s);
  erase(&s, pos);
  print(s);
  destroy(s);

}

void f4()
{
  SList* s = NULL;
  push_back(&s, 1);
  print(s);

  SList* pos = find(s, 1);
  insert(&s, pos, 2);
  insert(&s, pos, 3);
  insert(&s, pos, 4);
  insert(&s, pos, 5);
  print(s);

  erase(&s, pos);
  print(s);

  while (s != NULL)
  {
    erase(&s, s);
  }
  print(s);
}

int main()
{
  //f1();
  //f2();
  //f3();
  f4();
  return 0;
}

