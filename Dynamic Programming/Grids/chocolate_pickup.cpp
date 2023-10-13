// Chocolate Pickup

/*
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. 
Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible 
with the help of his friends. Initially, Alice is in the top-left position i.e. (0, 0), and 
Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their 
current cell to the cells just below them. When anyone passes from any cell, he will pick 
all chocolates in it, and then the number of chocolates in that cell will become zero. If 
both stay in the same cell, only one of them will pick the chocolates in it. If Alice or Bob 
is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will 
always stay inside the ‘GRID’. Your task is to find the maximum number of chocolates Ninja 
can collect with the help of his friends by following the above rules.
*/

#include<bits/stdc++.h>
using namespace std;

int func(int i,int j,int q,int r,int c,vector<vector<int>>& v,vector<vector<vector<int>>> &dp){
    if(j<0||q<0||j>=c||q>=c)return -1e8;
    if(i==r-1){
        if(j==q)return v[i][j];
        else return v[i][j]+v[i][q];
    }
    if(dp[i][j][q]!=-1)return dp[i][j][q];
    int mx=-1e8;
    for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
            int val=0;
            if(j==q)val=v[i][j];
            else val=v[i][j]+v[i][q];
            val+=func(i+1,j+di,q+dj,r,c,v,dp);
            mx=max(mx,val);
        }
    }
    return dp[i][j][q]= mx;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<bool>> dp(r,vector<int>(c,-1));
}

int main()
{
    
    
    return 0;
}