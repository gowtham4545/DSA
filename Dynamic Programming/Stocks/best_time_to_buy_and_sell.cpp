// Best Time to Buy and Sell Stocks

/*
You are given an array/list 'prices' where the elements of the array represent the prices of the 
stock as they were yesterday and indices of the array represent minutes. Your task is to find and 
return the maximum profit you can make by buying and selling the stock. You can buy and sell the 
stock only once.
*/

#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &arr){
    int n=arr.size();
    int mx=arr[n-1],mn=arr[n-1],best=0;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>mx){
            mx=arr[i];
            mn=mx;
        }
        else mn=min(mn,arr[i]);
        best=max(best,mx-mn);
    }
    return best;
}

int main()
{
    
    
    return 0;
}