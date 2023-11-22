// Write a program to reverse an array

#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v){
    int n=v.size();
    for(int i=0;i<=n/2;i++)swap(v[i],v[n-1-i]);
}

int main()
{
    vector<int> v={1,2,3,4,5};
    reverse(v);
    for(auto i:v)cout<<i<<' ';
    return 0;
}