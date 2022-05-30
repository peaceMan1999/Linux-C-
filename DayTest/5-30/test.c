#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("test begin\n");
    printf("os env : %s\n", getenv("PATH"));
    printf("my env : %s\n", getenv("MYVAL"));

    return 0;
}
