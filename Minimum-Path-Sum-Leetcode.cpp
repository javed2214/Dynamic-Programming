// Minimum Path Sum - LeetCode
// https://leetcode.com/problems/minimum-path-sum/

/************** METHOD 1 **************/
// O(n * m) Space
// O(n * m) Time

int minPathSum(vector<vector<int>> &grid){

	int n = grid.size();
	int m = grid[0].size();

	vector <vector<int>> dp(n, vector<int> (m, grid[0][0]));

	for(int i=1;i<n;i++) dp[i][0] = dp[i-1][0] + grid[i][0];

	for(int i=1;i<m;i++) dp[0][i] = dp[0][i-1] + grid[0][i];

	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

	return dp[n-1][m-1];
}


/************** METHOD 2 **************/
// O(1) Space
// O(n * m) Time

int minPathSum(vector<vector<int>> &grid){

	int n = grid.size();
	int m = grid[0].size();

	for(int i=1;i<m;i++) grid[0][i] += grid[0][i-1];

	for(int i=1;i<n;i++){
		grid[i][0] += grid[i-1][0];
		for(int j=1;j<m;j++){
			grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
		}
	}
	return grid[n-1][m-1];
}