// Minimum insertions to make a string palindrome

/*
A palindrome string is one that reads the same backward as well as forward.
You are given a string 'str'.
Find the minimum number of characters needed to insert in 'str' to make it a palindromic string.
*/

int lcs(string &s,string &t){
	int n=s.length(),m=t.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int minimumInsertions(string &str)
{
	int n=str.length();
	string t=str;
	reverse(t.begin(),t.end());
	return n-lcs(str,t);
}
