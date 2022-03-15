#include "seqlist.h"

int main()
{
  Seqlist s;
  Init(&s);
  
  push_back(&s, 1);
  push_back(&s, 2);
  push_back(&s, 3);
  push_back(&s, 4);
  push_back(&s, 5);
  print(&s);

  push_front(&s, 0);
  print(&s);

  pop_back(&s);
  pop_back(&s);
  pop_back(&s);
  print(&s);

  pop_front(&s);
  pop_front(&s);
  pop_front(&s);
  print(&s);

  Destroy(&s);
  return 0;
}
