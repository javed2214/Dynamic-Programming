// Unique Paths - II LeetCode
// https://leetcode.com/problems/unique-paths-ii/
// Ref: https://www.youtube.com/watch?v=AmRvCR6B5no

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){

	long n = obstacleGrid.size();
	long m = obstacleGrid[0].size();

	vector <vector<long>> dp(n, vector<long> (m, 0));   // 2-d Vector Initialized with 0 

	for(int i=0;i<n;i++){
		if(obstacleGrid[i][0]) break;
		else dp[i][0] = 1;
	}

	for(int i=0;i<m;i++){
		if(obstacleGrid[0][i]) break;
		else dp[0][i] = 1;
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(obstacleGrid[i][j] != 1)
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}

	return dp[n-1][m-1];
}