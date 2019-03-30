#include<iostream>
using namespace std ;

int partition1(int a[] , int start , int end1) {
int pivot = a[end1] ;
int pIndex = start ;
for(int i=start ; i<end1 ; i++) {
    if(a[i]<=pivot) {
        swap(a[i] , a[pIndex]) ;
        pIndex++ ;
    }
}
swap(a[pIndex] , a[end1]) ;
return pIndex ;
}

void quicksort(int a[] , int start , int end1) {
if(start < end1) {
    int pIndex = partition1(a , start , end1) ;
    quicksort(a , start , pIndex -1) ;
    quicksort(a , pIndex+1 , end1) ;
}
}

int main() {
int a[20] , n  , i ;
cout<<"//Program No. 5 Quick Sort"<<endl<<endl;
cout<<"Enter no. of elements :"<<endl ;
cin>>n ;
cout<<"Enter Elements :"<<endl ;
for(i=0; i<n; i++) cin>>a[i] ;
quicksort(a , 0 , n-1) ;
cout<<"Elements after sorting :"<<endl ;
for(i=0; i<n; i++) cout<<a[i]<<" " ;
return 0 ;
}
