#include "Stack.h"

int main()
{
  Stack st;
  Init(&st);
  Push(&st, 1);
  Push(&st, 2);
  Push(&st, 3);
  Push(&st, 7);
  Push(&st, 5);
  Print(&st);
  // 12375

  Empty(&st);
  //非空

  Top(&st);
  // 5
  Size(&st);
  // 5

  Pop(&st);  
  Pop(&st);  
  Pop(&st);
  Print(&st);
  //12

  Top(&st);
  // 5
  Size(&st);
  // 2 

  Delete(&st);
  Size(&st);
  Empty(&st);
  // 0 空

  return 0;
}
