// Longest Common Substring

/*
You are given two strings, 'str1' and 'str2'. You have to find the length of the longest common substring.
A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" 
or "cda" are not.
*/

#include "vector"

vector<vector<int>> dp;

int lcs(string &s, string &t){
    int m=s.length(),n=t.length();
	dp=vector<vector<int>>(m+1,vector<int>(n+1,0));
    int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
			else dp[i][j]=0;
		}
	}
	return ans;
}