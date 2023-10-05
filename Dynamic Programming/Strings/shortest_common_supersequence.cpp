// Shortest Common Supersequence

/*
Given two strings, ‘A’ and ‘B’. Return the shortest supersequence string ‘S’, 
containing both ‘A’ and ‘B’ as its subsequences. If there are multiple answers, return any of them.
Note: A string 's' is a subsequence of string 't' if deleting some number of characters from 't' 
(possibly 0) results in the string 's'.
*/

#include <bits/stdc++.h> 
using namespace std;

string lcs(string &s,string &t){
	int n=s.length(),m=t.length();
    string ans="";
    // normal lcs algo
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
    // tracking
    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+=s[i-1];
            i--;
        }
        else{
            ans+=t[j-1];
            j--;
        }
    }
    while(i>0)ans+=s[--i];
    while(j>0)ans+=t[--j];
    reverse(ans.begin(),ans.end());
    return ans;
}
string shortestSupersequence(string a, string b)
{
	return lcs(a,b);
}