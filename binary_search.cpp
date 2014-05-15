/*************************************************************************
	> File Name: binary_search.cpp
	> Author: dailiang
	> Mail: csdailiang@foxmail.com 
	> Created Time: Thu 15 May 2014 03:19:33 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int binary_search(int a[], int size, int goal)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] ==  goal) return mid;
        else if (a[mid] > goal) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(a) / sizeof(a[0]);

    cout << binary_search(a, size, 8) << endl;
    return 0;
}
