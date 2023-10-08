// Best Time to Buy and Sell Stock IV

/*
You have been given an array 'PRICES' consisting of 'N' integers where PRICES[i] denotes the price of a 
given stock on the i-th day. You are also given an integer 'K' denoting the number of possible transactions 
you can make.
Your task is to find the maximum profit in at most K transactions. A valid transaction involves buying 
a stock and then selling it.
Note:
You can’t engage in multiple transactions simultaneously, i.e. you must sell the stock before rebuying it.
*/

// Hint: Advancement of 3rd stocks program, changing limit from 2 to K.

#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices, int n, int K)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(K+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int k=1;k<=K;k++){
            dp[i][0][k]=max(dp[i+1][1][k-1]+prices[i],dp[i+1][0][k]);
            dp[i][1][k]=max(dp[i+1][0][k]-prices[i],dp[i+1][1][k]);
        }
    } 
    return dp[0][1][K];
}