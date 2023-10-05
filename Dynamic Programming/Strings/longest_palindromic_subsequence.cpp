// Longest Palindromic Subsequence

/*
You have been given a string ‘A’ consisting of lower case English letters. 
Your task is to find the length of the longest palindromic subsequence in ‘A’.
A subsequence is a sequence generated from a string after deleting some or no characters 
of the string without changing the order of the remaining string characters. (i.e. “ace” 
is a subsequence of “abcde” while “aec” is not). A string is said to be palindrome if the 
reverse of the string is the same as the actual string. For example, “abba” is a palindrome, 
but “abbc” is not a palindrome.
*/

#include <bits/stdc++.h> 

vector<vector<int>> dp;


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

int longestPalindromeSubsequence(string s)
{
    int n=s.length();
    string t=s;
    reverse(t.begin(),t.end());
    
    return lcs(s,t);
}