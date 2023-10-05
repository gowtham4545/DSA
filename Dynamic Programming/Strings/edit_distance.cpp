// Edit distance

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(string a,string b,int i,int j){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(a[i]==b[j])return f(a,b,i-1,j-1);
        return min(f(a,b,i-1,j-1),min(f(a,b,i-1,j),f(a,b,i-1,j-1)))+1;
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution s;
    cout<<s.minDistance("a","ab")<<endl;
    cout<<s.f("horse","ros",4,2)<<endl;
    return 0;
}