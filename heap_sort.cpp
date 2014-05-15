/*************************************************************************
	> File Name: heap_sort.cpp
	> Author: dailiang
	> Mail: csdailiang@foxmail.com 
	> Created Time: Thu 15 May 2014 11:17:53 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void heap_bubble_down(int a[], int i, int n) // insert a head "i" in a sorted sub-heap
{
    int val = a[i], par = i; 
    i = 2 * par + 1;
    while (i < n)
    {
        if (i + 1 < n && a[i + 1] < a[i]) i += 1; // find the smaller child
        if (a[i] >= val) break; // find the position to insert
        a[par] = a[i];
        par = i;
        i = 2 * par + 1;
    }
    a[par] = val;
}

void heap_init(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) heap_bubble_down(a, i, n);
}

void heap_sort(int a[], int n)
{
    heap_init(a, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[i], a[0]);
        heap_bubble_down(a, 0, i);
    }
}


void print(int a[], int size)
{
    for (int i = 0; i < size; i++) cout << a[i] << " ";
    cout << endl;
}


int main()
{
    int a[] = {3, 4, 5, 0, 1, 2, -1, 3, -4, -5, -2, -9, -8, -4, 9, 10, -20};
    int size = sizeof(a) / sizeof(a[0]);

    heap_sort(a, size);
    cout << "heap_sort:" << endl;
    print(a, size);


    return 0;
}

