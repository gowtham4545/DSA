// TODO: Count Ways To Reach The N-th Stairs

/*
You have been given a number of stairs. Initially, you are at the Oth stair, 
and you need to reach the Nth stair. Each time you can either climb one step or two steps. 
You are supposed to return the number of distinct ways in which you can climb from the Oth step to Nth step
*/

#include <bits/stdc++.h> 
int countDistinctWays(int n) {
    int mod=(int)(1e9+7);
    vector<unsigned long long> v(n+1,0);
    v[0]=1;
    v[1]=1;
    for(int i=2;i<=n;i++)v[i]=(v[i-1]+v[i-2])%mod;
    return v[n]%(int)(1e9+7);
}