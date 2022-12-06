#include<iostream>
using namespace std;

int binary_search(int a[],int low,int high,int key){
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        if(a[mid]<key)low=mid+1;
        if(a[mid]>key)high=mid-1;
    }
    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n=7;
    cout<<binary_search(a,0,n-1,4);
    return 0;
}