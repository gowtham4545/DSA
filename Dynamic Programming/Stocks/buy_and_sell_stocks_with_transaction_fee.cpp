// Best Time to Buy and Sell Stock with Transaction Fee

/*
You are given an array 'prices' of size 'n', denoting the price of stocks on 'n' days.
Rahul can buy one stock at a time, and he must sell it before buying stock on another day.
The entire transaction of selling and buying the stock requires some transaction fee, given as 'fee'.
Find the maximum profit Rahul can achieve by trading on the stocks.
*/

// Advancement of 2nd problem, for every transaction a transaction fee is deducted.

#include<bits/stdc++.h>
using namespace std;

int getMaximumProfit(vector<int> arr, int n,int fee)
{
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1;i>=0;i--){
        dp[i][0]=max(dp[i+1][1]+arr[i],dp[i+1][0]);
        dp[i][1]=max(dp[i+1][0]-arr[i]-fee,dp[i+1][1]);
    }
    return dp[0][1];
}
int maximumProfit(vector<int> &prices, int n, int fee)
{
	return getMaximumProfit(prices, n, fee);
}

int main()
{
    
    
    return 0;
}