#include "proc.h"

void Go()
{
    char arr[102];
    memset(arr, '\0', sizeof(arr));
    int i = 0;
    char *sign = "|/-\\";
    while (i <= 100)
    {
        printf("[%-100s][%3d%%][%c]\r", arr, i, sign[i%4]);
        fflush(stdout);
        usleep(100000);
        arr[i] = '#';
        i++;
    }
    printf("\n");
}
