#include <stdio.h>
#include <stdlib.h>

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


void merge(int* arr, int* tmp, int begin1, int end1, int begin2, int end2)
{
    int j = begin1, i = j;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (arr[begin1] < arr[begin2]){
            tmp[j++] = arr[begin1++];
        }else{
            tmp[j++] = arr[begin2++];
        }
    }
    // 其中一个走完了
    while (begin1 <= end1)
    {
        tmp[j++] = arr[begin1++]; 
    }
    while (begin2 <= end2)
    {
        tmp[j++] = arr[begin2++]; 
    }

    // int i = begin1; i不能在这里定义，因为begin1已经++过了
    for (; i <= end2; i++) // <= end2, 因为right已经减过1了
    {
        arr[i] = tmp[i];
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

void Sort(int* arr, int* tmp, int left, int right)
{
    if (left >= right){
        return;
    }

    int mid = (left + right) >> 1;

    Sort(arr, tmp, left, mid);
    Sort(arr, tmp, mid+1, right);

    int begin1 = left, begin2 = mid+1, end1 = mid, end2 = right;
    merge(arr, tmp, begin1, end1, begin2, end2);
}

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 1, 12, 2, 8, 10, 3};
    int sz = sizeof(arr)/sizeof(arr[0]);

    Print(arr, sz);
    // 排序
    int left = 0, right = sizeof(arr) / sizeof(arr[0])-1; 
    
    int* tmp = (int*) malloc (sizeof(int)* sz);
    if (tmp == NULL){
        perror("malloc");
        return -1;
    }

    Sort(arr, tmp, left, right);

    Print(arr, sz);

    return 0;
}






