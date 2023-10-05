// Distinct Subsequences

/*
A Subsequence of a string is the string that is obtained by deleting 0 or more letters 
from the string and keeping the rest of the letters in the same order.
We are given two strings, 'str' and 'sub'.
Find the number of subsequences of 'str' which are equal to 'sub'.
*/

#include<bits/stdc++.h>
using namespace std;

int f(string a,string b,int i,int j){
    if(j<0)return 1;
    if(i<0)return 0;
    if(a[i]==b[j])return f(a,b,i-1,j-1) + f(a,b,i-1,j);
    return f(a,b,i-1,j);
}

int distinctSubsequences(string &str, string &sub)
{
	int n=str.length(),m=sub.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str[i-1]==sub[j-1])dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][m];
}

int main()
{
    string str="brootgroot",sub="brt";
    cout<<distinctSubsequences(str,sub);
    
    return 0;
}