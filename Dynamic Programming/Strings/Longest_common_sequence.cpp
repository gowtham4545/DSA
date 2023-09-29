#include<bits/stdc++.h>

vector<vector<int>> dp;

int f(int i1,int i2,string s,string t){
	if(i1<0 || i2<0)return 0;
	if(dp[i1][i2]!=-1)return dp[i1][i2];
	if(s[i1]==t[i2])return dp[i1][i2]= f(i1-1,i2-1,s,t)+1;
	else
	return dp[i1][i2]= max(f(i1-1,i2,s,t),f(i1,i2-1,s,t));
}

int lcs(string s, string t)
{
	int m=s.length(),n=t.length();
	dp=vector<vector<int>>(m+1,vector<int>(n+1,0));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}