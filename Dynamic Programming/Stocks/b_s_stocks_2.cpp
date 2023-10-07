// Best Time to Buy and Sell Stock II

/*
You have been given stock values/prices for N number of days. Every i-th day signifies 
the price of a stock on that day. Your task is to find the maximum profit which you can 
make by buying and selling the stocks.
*/

#include<bits/stdc++.h>
using namespace std;

long f(long *arr,int i,int n,int buy){
    if(i==n)return 0;
    if(buy){
        return max(f(arr,i+1,n,0)-arr[i],f(arr,i+1,n,1));
    }
    else return max(arr[i]+f(arr,i+1,n,1),f(arr,i+1,n,0));
}

long getMaximumProfit(long *arr, int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1;i>=0;i--){
        dp[i][0]=max(dp[i+1][1]+arr[i],dp[i+1][0]);
        dp[i][1]=max(dp[i+1][0]-arr[i],dp[i+1][1]);
    }
    return dp[0][1];
}

int main()
{
    
    
    return 0;
}