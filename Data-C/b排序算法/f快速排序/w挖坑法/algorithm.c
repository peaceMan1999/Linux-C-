#include <stdio.h>

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
            return right;
        }
    }
}

int Dig(int* arr, int left, int right)
{
    int mid = GetMid(arr, left, right);
    Swap(&arr[left], &arr[mid]);

    int hole = arr[left]; // 原坑位坑主

    while (left < right)
    {
        while (left < right && arr[right] >= hole){
            right--;
        }
        Swap(&arr[left], &arr[right]);
        while (left < right && arr[left] <= hole){
            left++;
        }
        Swap(&arr[left], &arr[right]);
    }
    arr[left] = hole;
    int meet = left;

    return meet;
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

void Sort(int* arr, int left, int right)
{
    if (left >= right){
        return;
    }
    int key = Dig(arr, left, right);

    Sort(arr, left, key-1);
    Sort(arr, key+1, right);
}

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 1, 12, 2, 8, 10, 3};
    int sz = sizeof(arr)/sizeof(arr[0]);

    Print(arr, sz);
    // 排序
    int left = 0, right = sizeof(arr) / sizeof(arr[0])-1; 
    GetMid(arr, left, right);

    Sort(arr, left, right);

    Print(arr, sz);

    return 0;
}






