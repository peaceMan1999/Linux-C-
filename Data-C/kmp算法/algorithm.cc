#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void GetNext(string& target, int* next)
{
    int n = target.size();
    next[0] = 0;
    // 获取next数组, j为前缀，i为后缀
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < n; i++)
        {
            while (j > 0 && target[j] != target[i]) // 用while不要用if
            {
                j = next[j-1];
            }
            if (target[j] == target[i])
            {
                j++;
            }
            next[i] = j;
        }
    }
}

bool IsIn(string& source, string& target)
{
    int len = target.size();
    int lenght = source.size();
    int* next = (int*) malloc (sizeof(int)*len);
    GetNext(target, next);

    int j = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (i > 0 && source[i] != target[j]){
            if (i == 0){
                j = 0;
            }else{
                j = next[j-1];
            }
        }else{
            j++;
        }
        if (j == len){
            return true;
        }
    }
    return false;
}

int main()
{
    string source = "aabaabaab";
    string target = "aabaaf";

    bool flag = IsIn(source, target);
    if (flag){
        cout << "1" << endl;
    }else{
        cout << "0" << endl;
    }

    return 0;
}






