#include <stdio.h>

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void Sort(int* arr, int sz)
{
    int i = sz-1; 
    for (; i >= 0; i--)
    {
        int j = 0, count = 0;
        for (; j < i; j++)
        {
            if (arr[j] > arr[j+1]){
                Swap(&arr[j], &arr[j+1]);
                count = 1;
            }
        }

        if (count == 0){
            // 说明不用判断了
            break;
        }
    }

}

void Print(int* arr, int sz)
{
    int j = 0;
    for (; j < sz; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 1, 12, 2, 8, 10, 3};
    int sz = sizeof(arr)/sizeof(arr[0]);

    Print(arr, sz);
    // 排序
    Sort(arr, sz);
    
    Print(arr, sz);

    return 0;
}






