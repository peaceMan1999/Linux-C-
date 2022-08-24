#include <stdio.h>

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Sort(int* arr, int sz)
{
    int left = 0, right = sz-1; 
    while (left < right)
    {
        int minsort = left, maxsort = right;  
        int i = left;
        for (; i < right; i++)
        {
            if (arr[minsort] > arr[i]){
                minsort = i;
            }
            else if (arr[maxsort] < arr[i]){
                maxsort = i;
            }
        }
        Swap(&arr[left], &arr[minsort]);
        // 判断一下最大是不是原来的最小位置，以免把换到的最小值换过来了
        if (maxsort == left){
            maxsort = minsort;
        }
        Swap(&arr[right], &arr[maxsort]);
        left++;
        right--;
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






