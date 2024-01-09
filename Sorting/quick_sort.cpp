// Quick Sort

/*
Intuition:
we'll chose a pivot from the array (It may be either first element or the last element or any element you chose). The need is all the elements present on the left side of the pivot must be smaller than the pivot and allthe elements that are present right to the pivot must be greater than the pivot. 

So we'll find the pivot position of the first element through iterating all the elements and swaping element.After we get the pivot position, we swap it with the first element. Then we divide the array into 2 parts at the pivot and carry the function for both the subarrays.
*/

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int l,int h){
    int pivot=v[l];
    int i=l+1,j=h;
    while(i<=j){
        while(v[i]<=pivot)i++;
        while(v[j]>pivot)j--;
        if(i<j)swap(v[i],v[j]);
    }
    swap(v[l],v[j]);
    return j;
}

void quickSort(vector<int> &v,int l,int h){
    if(l<h){
        int p=partition(v,l,h);
        quickSort(v,l,p-1);
        quickSort(v,p+1,h);
    }
}

int main()
{
    vector<int> v={7,4,6,3,2,5,1};
    quickSort(v,0,6);
    for(auto i:v)
    cout<<i<<' ';
    
    return 0;
}