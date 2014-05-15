/*************************************************************************
	> File Name: merge_sort.h
	> Author: dailiang
	> Mail: csdailiang@foxmail.com 
	> Created Time: Thu 15 May 2014 10:09:25 AM CST
 ************************************************************************/

 #include<iostream>

 using namespace std;

void merge_sort_recu(int*, int, int, int*);
void merge_array(int*, int, int, int, int*);

bool merge_sort(int a[], int size)
{
    // allocate new space for sorting
    int *tmp = new int[size];
    if (tmp == NULL) return false;
    merge_sort_recu(a, 0, size - 1, tmp);
    delete[] tmp;
    return true;
}

void merge_sort_recu(int a[], int l, int r, int tmp[])
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort_recu(a, l, mid, tmp);  // sort left array
        merge_sort_recu(a, mid+1, r, tmp); // sort right array
        merge_array(a, l, mid, r, tmp); // merge two sorted array
    }
}

void merge_array(int a[], int l, int mid, int r, int tmp[])
{
    int first1 = l, last1 = mid;
    int first2 = mid + 1, last2 = r;
    int k = 0;

    while (first1 <= last1 && first2 <= last2)
    {
        if (a[first1] <= a[first2]) tmp[k++] = a[first1++];
        else tmp[k++] = a[first2++];
    }

    while(first1 <= last1) tmp[k++] = a[first1++];
    while(first2 <= last2) tmp[k++] = a[first2++];

    // copy sorted array from tmp[] to a[]
    for (int i = 0; i < k; i++)
        a[l + i] = tmp[i];
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

    merge_sort(a, size);
    cout << "merge_sort:" << endl;
    print(a, size);

    return 0;
}
