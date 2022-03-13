#include "proc.h"

void proc()
{
  char p[N];
  memset(p, '\0', sizeof(p));
  char point[] = "|/-\\";

  int i = 0;
  while ( i < 100 )
  {
    p[i++] = '#';
    printf("[%-100s][%3d%%][ %c ]\r", p, i, point[i%4]);
    fflush(stdout);
    usleep(100000);
  }
  printf("\n");
  return;
}

