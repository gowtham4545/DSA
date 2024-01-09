// Quick Select Algorithm

/*
This is derived algorithm from Quick Sort algorithm.

It is about to find an element for particular index in sorted array.
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

int quickSelect(vector<int> &v,int l,int h,int k){
    if(l==h)return v[l];
    int p=partition(v,l,h);
    if(k==p)
        return v[p];
    else if(k<p)
        h=p-1;
    else
        l=p+1;
    return quickSelect(v,l,h,k);
}

int main()
{
    vector<int> v={7,4,6,3,2,5,1};
    cout<<quickSelect(v,0,6,6);
    
    return 0;
}