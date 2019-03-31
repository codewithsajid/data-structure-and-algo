#include<iostream>
using namespace std;

void Merge(int *a, int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid+1, k = low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=mid)
        temp[k++] = a[i++];

    while(j<=high)
        temp[k++] = a[j++];

    for(int s=low; s<=high; s++)
        a[s] = temp[s];
}

void merge_sort(int *a, int low, int high)
{
    if(low >= high)
        return;

    int mid = (high+low)/2;
    merge_sort(a, low, mid);
    merge_sort(a, mid+1, high);
    Merge(a, low, mid, high);
}

int main()
{
    int size;
    int a[100];
    cout<<"Enter size of array: ";
    cin>>size;
    cout<<"Enter elements to be sorted: ";
    for(int i=0; i<size; i++)
        cin>>a[i];
    merge_sort(a, 0, size-1);
    cout<<"Elements after sorting are: ";
    for(int i=0; i<size; i++)
        cout<<a[i]<<" ";
    return 0;
}
