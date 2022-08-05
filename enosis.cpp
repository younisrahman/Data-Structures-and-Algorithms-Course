#include <bits/stdc++.h>
//#include<iostream>
using namespace std;
int main()
{
    int arr[3] = {1, 2, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int a = 7;
    if (arr[2] < a)
    {
        if ((arr[1] * 10) + arr[2] > a)
        {
            arr[1] = (((arr[1] * 10) + arr[2]) / 10) - (a / 10);
            arr[2] = arr[2] - abs((((arr[1] * 10) + arr[2]) % 10) - (a / 10));
        }
        else
        {
        }
    }
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
    return 0;
}