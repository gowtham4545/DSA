// Diagonal Traverse

/*

Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
     1  2  3
     4  5  6
     7  8  9

     1 -> 2 -> 4 -> 7 -> 5 -> 3 -> 6 -> 8 -> 9
   
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> v;
        int m=mat.size();
        if(m==0)return v;
        int n=mat[0].size();
        int row=0,col=0;
        bool up=true;
        while(row<m && col<n){
            if(up){
                while(row>0 && col<n-1){
                    v.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                v.push_back(mat[row][col]);
                if(col==n-1)row++;
                else col++;
            }
            else{
                while(row<m-1 && col>0){
                    v.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                v.push_back(mat[row][col]);
                if(row==m-1)col++;
                else row++;
            }
            up=!up;
        }
        return v;
    }
};

// ====================================================================================================


// TODO: Type 2
/*
    1  2  3  4  5
    6  7
    8
    9  10 11 
    12 13 14 15 16

    1 » 6 » 2 » 8 » 7 » 3 » 9 » 4 » 12 » 10 » 5 » 13 » 11 » 14 » 15 » 16
*/

// Approach 1: Group Elements by the Sum of Row and Column Indices
// Ref (https://leetcode.com/problems/diagonal-traverse-ii/editorial/)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int> v;
        if(!n)return v;
        int m=0;
        for(auto arr:nums)m=max(m,int(arr.size()));
        if(!m)return v;
        vector<vector<int>> t(n+m,vector<int>({}));
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                t[i+j].insert(t[i+j].begin(),nums[i][j]);
            }
        }
        for(auto arr:t){
            for(auto val:arr)v.push_back(val);
        }
        return v;
    }
};

// ----------------------------------------------------------------------------------------------
// Approach 2: Breadth First Search

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        vector<int> ans;
        
        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            ans.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) {
                queue.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) {
                queue.push({row, col + 1});
            }
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    
    return 0;
}