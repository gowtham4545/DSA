// Minimum Number of Deletions and Insertions

/*
You are given 2 non-empty strings 's1' and 's2' consisting of lowercase English alphabets only.
In one operation you can do either of the following on 's1':
(1) Remove a character from any position in 's1'.
(2) Add a character to any position in 's1'.
Find the minimum number of operations required to convert string 's1' into 's2'.
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

int canYouMake(string &s1, string &s2){
	int n=s1.length(),m=s2.length();
    return m+n-2* lcs(s1,s2);
}