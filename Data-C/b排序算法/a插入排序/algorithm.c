#include <stdio.h>

// 从i往前查找
void Sort(int *arr, int sz)
{
    int i = 0;
    for (; i < sz - 1; i++)
    {
        int end = i;
        int tmp = arr[end+1];

        while (end >= 0){
            if (tmp < arr[end])
            {
                arr[end+1] = arr[end];
                end--;
            }
            else
                break;
        }
        arr[end+1] = tmp;
    }
}

int main()
{
    //int arr[] = {5, 3, 4, 7, 6, 8};
    int arr[] = {3, 4, 5, 6, 7, 1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    Sort(arr, sz);
    
    int i = 0;
    for (; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}