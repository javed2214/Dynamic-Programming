// https://leetcode.com/problems/unique-paths/

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?

#include<bits/stdc++.h>
using namespace std;

int main(){

	int r,c;
	cin>>r>>c;

	vector<vector<int>> dp(r, vector<int>(c,1));	// Filling 2D Vector with 1's

	for(int i=1;i<r;i++)
		for(int j=1;j<c;j++)
			dp[i][j]=dp[i-1][j]+dp[i][j-1];

	cout<<dp[r-1][c-1];

	return 0;
}
