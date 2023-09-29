// Uniqueu Paths

/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix, 
your destination is point ‘B’, which is the bottom-right cell of the same matrix. 
Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, 
your task is to find the total number of unique paths from the cell MATRIX[0][0] 
to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example, 
in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].
*/


#include <bits/stdc++.h> 

int func(int i,int j,vector<vector<int>> &v){
	if(i==0 && j==0)return 1;
	if(i<0 || j<0)return 0;
	if(v[i][j]!=-1)return v[i][j];
	v[i-1][j]=func(i-1,j,v);
	v[i][j-1]=func(i,j-1,v);
	return v[i][j-1]+v[i-1][j];
}

int uniquePaths(int m,int n){
	vector<vector<int>> v(m,vector<int>(n,0));
	for(int i=0;i<m;i++)v[i][0]=1;
	for(int i=0;i<n;i++)v[0][i]=1;
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			v[i][j]=v[i][j-1]+v[i-1][j];
		}
	}
	return v[m-1][n-1];
}