#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile int g_flag = 0;

void handler(int signo)
{
    printf("change flag\n");
    g_flag = 1;
}

int main()
{
    signal(SIGINT, handler);
    
    while (!g_flag){
    }
    printf("end\n");

    return 0;
}
