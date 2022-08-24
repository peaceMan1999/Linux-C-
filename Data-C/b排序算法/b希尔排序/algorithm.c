#include <stdio.h>


void Sort(int* arr, int sz)
{
    int grap = sz / 3 + 1; // 分隔数

    while (grap > 1)
    {
        int i = 0;
        for (; i < sz - grap; i++)
        {
            int end = i;
            int tmp = arr[i + grap];
            while (end >= 0)
            {
                if (arr[end] < tmp){
                    arr[end + grap] = arr[end];
                    end -= grap;
                }else{
                    break;
                }
            }
            arr[end + grap] = tmp;
        }
        grap = grap/3 + 1;
    }
    
    // 最后一次用插入,其实就是grap=1
    int i = 0;
    for (; i < sz-1; i++)
    {
        int end = i;
        int tmp = arr[end+1];
        while (end >= 0)
        {
            if (arr[end] > tmp){
                arr[end+1] = arr[end];
                end--;
            }else{
                break;
            }
        }
        arr[end + 1] = tmp;
    }

}


int main()
{
    //int arr[] = {5, 3, 4, 7, 6, 8};
    int arr[] = {3, 4, 5, 6, 7, 1, 12, 2, 8, 10, 3};
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