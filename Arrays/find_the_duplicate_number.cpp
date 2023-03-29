/*

Find the Duplicate Number
{ Amazon }

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.


*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int hash[n+1];
        for(int i=0;i<=n;i++)hash[i]=0;
        for(int i=0;i<=n;i++){
            if(hash[nums[i]]==0)hash[nums[i]]=1;
            else return nums[i];
        }
        return -1;
    }
};