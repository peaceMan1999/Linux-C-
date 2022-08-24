#include "Heap.h"

int main()
{
  int arr[] = {3, 7, 4, 9, 11, 25, 2, 6}; 
  
  Heap hp;
  int n = sizeof(arr) / sizeof(arr[0]);
  Init(&hp, arr, n);
  Print(&hp);
  Size(&hp);
  Emply(&hp);

  Push(&hp, 20);
  Push(&hp, 1);
  Push(&hp, 16);
  Print(&hp);
  Size(&hp);
  Top(&hp);

  Pop(&hp);
  Pop(&hp);
  Pop(&hp);
  Print(&hp);
  Size(&hp);
  //Print(&hp);
  return 0;
}




