// WildCard Pattern Matching

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

#include<bits/stdc++.h>
using namespace std;

bool func(string p,string t,int i,int j){
   if(i<0 && j<0)return true;
   if(i<0)return false;
   if(j<0){
      for(int k=0;k<=i;k++)
         if(p[k]!='*')return false;
      return true;
   }
   if(p[i]==t[j] || p[i]=='?')return func(p,t,i-1,j-1);
   if(p[i]=='*')return func(p,t,i,j-1) | func(p,t,i-1,j);
   return false;
}

bool isAllStars(string &S1, int i) {
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

bool wildcardMatching(string pattern, string text)
{
   int n=pattern.length(),m=text.length();
   vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
   dp[0][0]=1;
   for(int i=1;i<=n;i++){
      dp[i][0]=isAllStars(pattern,i);
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(pattern[i-1]==text[j-1] || pattern[i-1]=='?')dp[i][j]=dp[i-1][j-1];
         else if(pattern[i-1]=='*')dp[i][j]=dp[i][j-1] || dp[i-1][j];
         else dp[i][j]=false;
      }
   }
   return dp[n][m];
}


int main()
{
    cout<<wildcardMatching("**","abdefcd");
    
    return 0;
}