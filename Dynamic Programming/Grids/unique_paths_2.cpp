// Unique Paths II

/*
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the 
right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a 
blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and 
(i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1)dp[i][j]=0;
            else if(i==0 && j==0 )dp[i][j]=1;
            else{
                int up=0,left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=(up+left)%(int)(1e9+7);
            }
        }
    }
    return dp[n-1][m-1];
}

int main()
{
    
    
    return 0;
}