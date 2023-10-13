// Maximum Path Sum in the matrix

/*
You have been given an N*M matrix filled with integer numbers, find the maximum sum that can 
be obtained from a path starting from any cell in the first row to any cell in the last row.
From a cell in a row, you can move to another cell directly below that row, or diagonally 
below left or right. So from a particular cell (row, col), we can move in three directions i.e.
Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)
*/

#include<bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &arr)
{
    int mx=INT_MIN,n=arr.size(),m=arr[0].size();
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            int d=INT_MIN,dl=INT_MIN,dr=INT_MIN;
            if(j>0)dl=arr[i+1][j-1]+arr[i][j];
            if(j<m-1)dr=arr[i+1][j+1]+arr[i][j];
            d=arr[i+1][j]+arr[i][j];
            arr[i][j]=max(max(d,dl),(dr));
        }
    }
    for(int i=0;i<m;i++)mx=max(mx,arr[0][i]);
    return mx;
}

int main()
{
    
    
    return 0;
}