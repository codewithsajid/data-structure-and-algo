#include<iostream>
using namespace std;

int Bin_Search(int *A, int start, int end, int element)
{
    int middle = (start+end)/2;
    if(element==A[middle])
        return middle;
    else if(element < A[middle])
        return Bin_Search(A,start,middle-1,element);
    else if(element > A[middle])
        return Bin_Search(A,middle+1,end,element);
    else
        cout<<"DATA NOT FOUND";
}

int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int element;
    cout<<"ENTER ELEMENT TO FIND POSITION : ";
    cin>>element;
    cout<<element<<" IS PRESENT AT "<<Bin_Search(A,0,9,element)<<" POSITION";
    return 0;
}
