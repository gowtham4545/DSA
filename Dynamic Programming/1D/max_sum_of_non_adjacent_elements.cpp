// Maximum sum of non-adjacent elements

/*
You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the 
subsequence with the constraint that no two elements are adjacent in the given array/list.
*/


#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    if(n==1)return nums[0];
    if(n==2)return max(nums[0],nums[1]);
    vector<int> v;
    v.push_back(nums[0]);
    v.push_back(nums[1]);
    for(int i=2;i<n;i++){
        v.push_back(nums[i]+v[i-2]);
        if(i!=2)v[i]=max(v[i],nums[i]+v[i-3]);
    }
    return max(v[n-1],v[n-2]);
}