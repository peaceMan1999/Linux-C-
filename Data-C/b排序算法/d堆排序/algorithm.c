#include <stdio.h>

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void AdjustDown(int* arr, int sz, int parent)
{
    int child = parent * 2 + 1;
    while (child < sz)
    {
        if (child < sz-1 && arr[child] < arr[child+1]){
            child++;
        }
        if(arr[child] > arr[parent]){
            Swap(&arr[child], &arr[parent]);
            parent = child;
            child = parent*2+1;
        }else{
            break;
        }
    }
}

void Sort(int* arr, int sz)
{
    // 建堆
    int parent = (sz-1-1)/2;
    for (; parent >= 0; parent--)
    {
        AdjustDown(arr, sz, parent);
    }

    while (sz > 0)
    {
        Swap(&arr[0], &arr[sz-1]);
        AdjustDown(arr, sz-1, 0); // 只需要建一次即可
        sz--;
    }
}

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 1, 12, 2, 8, 10, 3};
    int sz = sizeof(arr)/sizeof(arr[0]);

    int j = 0;
    for (; j < sz; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");

    Sort(arr, sz);
   
    int i = 0;
    for (; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;
}






