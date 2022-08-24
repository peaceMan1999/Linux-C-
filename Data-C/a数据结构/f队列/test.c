#include "Queue.h"

int main()
{
    Queue que;
    Init(&que);
    Push(&que, 1);
    Push(&que, 2);
    Push(&que, 3);
    Push(&que, 4);
    Push(&que, 5);
    Push(&que, 6);
    Print(&que);
    // 123456

    Size(&que);
    Emply(&que);
    QueueFront(&que);
    QueueBack(&que);
    // 6 fk 1 6

    Pop(&que);
    Pop(&que);
    Pop(&que);
    Print(&que);
    // 456

    QueueFront(&que);
    QueueBack(&que);
    // 4 6

    Delete(&que);
    Size(&que);
    Emply(&que);
    // 0 k

    return 0;
}










