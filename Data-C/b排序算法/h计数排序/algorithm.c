#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int GetMid(int* num, int left, int right)
{
    int mid = (left + right) >> 1;
    if (num[left] < num[mid])
    {
        if (num[left] > num[right]){
            return left;
        }else if (num[mid] < num[right]){
            return mid;
        }else{
            return right;
        }
    }
    else // num[left] > num[mid]
    {
        if (num[left] < num[right]){
            return left;
        }else if (num[mid] > num[right]){
            return mid;
        }else{
            return left;
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

void Sort(int* arr, int sz)
{
    int i = 0, max = arr[0], min = arr[0];
    for (; i < sz; i++)
    {
        if (arr[i] > max){
            max = arr[i];
        }else if (arr[i] < min){
            min = arr[i];
        }
    }
    // 建立相对映射节省空间
    int map = max - min + 1; // 加1以防都一样

    int* count = (int*) malloc (sizeof(int)* map);
    memset(count, 0, sizeof(int)*map);

    for (i = 0; i < sz; i++)
    {
        count[arr[i] - min]++;
    }

    int j = 0;
    for (i = 0; i < max; i++)
    {
        while (count[i] != 0){
            arr[j++] = i + min;
            count[i]--;
        }
    }
    free(count);
    count = NULL;
}

int main()
{
    int arr[] = {7, 4, 5, 3, 6, 20, 12, 2, 8, 10, 4};
    int sz = sizeof(arr)/sizeof(arr[0]);

    Print(arr, sz);
    // 排序
    Sort(arr, sz);

    Print(arr, sz);

    return 0;
}






