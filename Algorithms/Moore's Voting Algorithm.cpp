// Moore's Voting Algorithm

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume 
that the majority element always exists in the array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,el;
        for(auto i:nums){
            if(cnt==0){
                cnt++;
                el=i;
            }
            else if(el==i)cnt++;
            else cnt--;
        }
        int count=0;
        for(auto i:nums)if(i==el)count++;
        if(count>nums.size()/2)return el;
        else return -1;
    }
};

int main()
{
    Solution s;
    
    return 0;
}