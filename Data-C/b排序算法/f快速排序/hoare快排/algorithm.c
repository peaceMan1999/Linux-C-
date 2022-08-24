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
            return left;
        }
    }
}

int Hoare(int* arr, int left, int right)
{
    // 三数取中
    //int mid = GetMid(arr, left, right);
    //Swap(&arr[left], &arr[mid]);
    
    int key = left;

    while (left < right)
    {
        while (left < right && arr[right] >= arr[key]){
            right--;
        }
        while (left < right && arr[left] <= arr[key]){
            left++;
        }
        Swap(&arr[left], &arr[right]);
    }
    Swap(&arr[key], &arr[left]);
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

void Sort(int* arr, int left, int right, int sz)
{
    if (left >= right){
        return;
    }
    int key = Hoare(arr, left, right);
    Print(arr, sz);

    Sort(arr, left, key-1, sz);
    Sort(arr, key+1, right, sz);
}

int main()
{
    int arr[] = {7, 4, 5, 3, 6, 20, 12, 2, 8, 10, 4};
    int sz = sizeof(arr)/sizeof(arr[0]);

    Print(arr, sz);
    // 排序
    int left = 0, right = sizeof(arr) / sizeof(arr[0])-1; 

    Sort(arr, left, right, sz);

    Print(arr, sz);

    return 0;
}






