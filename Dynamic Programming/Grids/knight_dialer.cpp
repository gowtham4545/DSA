// Knight Dialer

/*
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, 
or two squares horizontally and one square vertically (with both forming the shape of an L).

We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell 
(i.e. blue cell).

    1   2   3
    4   5   6
    7   8   9
    *   0   #

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 
jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n,int c){
        if(!c)return 1;
        if(n==0)return f(4,c-1)+f(6,c-1);
        if(n==1)return f(8,c-1)+f(6,c-1);
        if(n==2)return f(7,c-1)+f(9,c-1);
        if(n==3)return f(4,c-1)+f(8,c-1);
        if(n==4)return f(3,c-1)+f(9,c-1)+f(0,c-1);
        if(n==6)return f(1,c-1)+f(7,c-1)+f(0,c-1);
        if(n==7)return f(2,c-1)+f(6,c-1);
        if(n==8)return f(1,c-1)+f(3,c-1);
        if(n==9)return f(2,c-1)+f(4,c-1);
        return 0;
    }
    int knightDialer(int n) {
        // int cnt=0;
        // for(int i=0;i<10;i++)cnt+=f(i,n-1);
        // return cnt;
        int mod=1e9+7;
        vector<vector<long long>> v(10,vector<long long>(n));
        for(int i=0;i<10;i++)v[i][0]=1;
        for(int i=1;i<n;i++){
            v[0][i]=(v[4][i-1]+v[6][i-1])%mod;
            v[1][i]=(v[8][i-1]+v[6][i-1])%mod;
            v[2][i]=(v[7][i-1]+v[9][i-1])%mod;
            v[3][i]=(v[4][i-1]+v[8][i-1])%mod;
            v[4][i]=(v[3][i-1]+v[9][i-1]+v[0][i-1])%mod;
            v[5][i]=0;
            v[6][i]=(v[1][i-1]+v[7][i-1]+v[0][i-1])%mod;
            v[7][i]=(v[2][i-1]+v[6][i-1])%mod;
            v[8][i]=(v[1][i-1]+v[3][i-1])%mod;
            v[9][i]=(v[4][i-1]+v[2][i-1])%mod;
        }
        long long cnt=0;
        for(int i=0;i<10;i++)cnt+=v[i][n-1];
        return cnt%mod;
    }
};

int main()
{
    Solution s;
    
    return 0;
}