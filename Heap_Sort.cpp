#include<iostream>
using namespace std;
int Size = 6;

void Max_Heapify(int A[], int i)
{
    int left = 2*i;
    int right = 2*i+1;
    int largest;
    if(left<=Size && A[left]>A[i])
        largest = left;
    else
        largest = i;
    if(right<=Size && A[right]>A[largest])
        largest = right;
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        Max_Heapify(A,largest);
    }
}

void Build_MaxHeap(int A[])
{
    int m = Size;
    while(m/2!=0)
    {
        Max_Heapify(A,m/2);
        m--;
    }
}

void HeapSort(int A[])
{
    Build_MaxHeap(A);
    while(Size!=1)
    {
        swap(A[1],A[Size]);
        Size--;
        Max_Heapify(A,1);
    }
}

int main()
{
    int A[Size], j;
    int n = Size;
    cout<<"Enter 6 elements for Array : "<<endl;
    for(j=1; j<=Size; j++)
        cin>>A[j];
    HeapSort(A);
    cout<<"Elements after Sorting : ";
    for(j=1; j<=n; j++)
        cout<<A[j]<<" ";
    return 0;
}


