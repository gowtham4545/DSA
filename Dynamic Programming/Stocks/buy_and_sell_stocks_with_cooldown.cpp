// Best Time to Buy and Sell Stock with Cooldown

/*
You are given a list of stock prices of size 'n' called ‘prices’, where ‘prices[i]’ represents the price on ‘i’th day.
Your task is to calculate the maximum profit you can earn by trading stocks if you can only hold one stock at a time.
After you sell your stock on the ‘i’th day, you can only buy another stock on ‘i + 2’ th day or later.
*/

// Hint: Advancement on 2nd problem, the condition is once you sell, you can't buy the very next day, 
// so jump to i+2

#include<bits/stdc++.h>
using namespace std;

int getMaximumProfit(vector<int> arr, int n)
{
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1;i>=0;i--){
        dp[i][0]=max(dp[i+2][1]+arr[i],dp[i+1][0]);
        dp[i][1]=max(dp[i+1][0]-arr[i],dp[i+1][1]);
    }
    return dp[0][1];
}

int stockProfit(vector<int> &prices){
    return getMaximumProfit(prices,prices.size());
}

int main()
{
    
    
    return 0;
}