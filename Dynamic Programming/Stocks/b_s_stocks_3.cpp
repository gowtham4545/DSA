// Best Time to Buy and Sell Stock III

/*
You are Harshad Mehta’s friend. He told you the price of a particular stock for the next ‘n’ days.
You are given an array ‘prices’ which such that ‘prices[i]’ denotes the price of the stock on the ith day.
You don't want to do more than 2 transactions. Find the maximum profit that you can earn from these transactions.
Note:
1. Buying a stock and then selling it is called one transaction.
2. You are not allowed to do multiple transactions at the same time. This means you have to sell the stock before buying it again. 
*/

#include<bits/stdc++.h>
using namespace std;

long f(long *arr,int i,int n,int buy,int cap){
    if(cap==0)return 0;
    if(i==n)return 0;
    if(buy){
        return max(f(arr,i+1,n,0,cap)-arr[i],f(arr,i+1,n,1,cap));
    }
    else return max(arr[i]+f(arr,i+1,n,1,cap-1),f(arr,i+1,n,0,cap));
}

int maxProfit(vector<int>& prices)
{
    // return f(prices,0,prices.size(),1,2);
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int i=n-1;i>=0;i--){
        for(int k=1;k<3;k++){
            dp[i][0][k]=max(dp[i+1][1][k-1]+prices[i],dp[i+1][0][k]);
            dp[i][1][k]=max(dp[i+1][0][k]-prices[i],dp[i+1][1][k]);
        }
    } 
    return dp[0][1][2];
}

int main()
{
    vector<int> v={1,3,1,2,4,8};
    cout<<maxProfit(v);
    
    return 0;
}