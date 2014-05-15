/*************************************************************************
	> File Name: quick_sort.cpp
	> Author: dailiang
	> Mail: csdailiang@foxmail.com 
	> Created Time: Thu 15 May 2014 08:56:07 AM CST
 ************************************************************************/

#include<iostream>

using namespace std;

void print(int a[], int size)
{
    for (int i = 0; i < size; i++) cout << a[i] << " ";
    cout << endl;
}


void qsort(int a[], int l, int r)
{
    if (l < r)
    {
        int l_iter = l, r_iter = r, pivot = a[l];
        while (l_iter < r_iter)
        {
            while (l_iter < r_iter && a[r_iter] >= pivot) r_iter--;
            if (l_iter < r_iter) a[l_iter++] = a[r_iter];
            while (l_iter < r_iter && a[l_iter] <= pivot) l_iter++;
            if (l_iter < r_iter) a[r_iter--] = a[l_iter];
        }
        a[l_iter] = pivot;
        qsort(a, l, l_iter - 1);
        qsort(a, l_iter + 1, r);
    }
}

void quick_sort(int a[], int size)
{
    qsort(a, 0, size - 1);
}


int main()
{
    int a[] = {3, 4, 5, 0, 1, 2, -1, 3, -4, -5, -2, -9, -8, -4, 9, 10, -20};
    int size = sizeof(a) / sizeof(a[0]);

    quick_sort(a, size);
    cout << "quick_sort:" << endl;
    print(a, size);


    return 0;
}

