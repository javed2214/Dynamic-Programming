// Minimum Falling Path Sum - LeetCode
// https://leetcode.com/problems/minimum-falling-path-sum/

/*
Given a square array of integers A, we want the minimum sum of a falling path through A.
A falling path starts at any element in the first row, and chooses one element from each row. 
The next row's choice must be in a column that is different from the previous row's column by at most one.
*/

class Solution{
public:
    int minFallingPathSum(vector<vector<int>>& A) {
    	
    	int n = A.size();
    	int m = A[0].size();

    	int dp[n][m];

    	for(int i=0;i<m;i++) dp[0][i] = A[0][i];    

    	for(int i=1;i<n;i++){
    		for(int j=0;j<m;j++){
    			dp[i][j] = dp[i-1][j] + A[i][j];
    			if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + A[i][j]);
    			if(j+1 < m) dp[i][j] = min(dp[i][j], dp[i-1][j+1] + A[i][j]);
    		}
    	}

    	int mi = INT_MAX;

    	for(int i=0;i<m;i++) mi = min(mi, dp[n-1][i]);

    	return mi;
    }
};