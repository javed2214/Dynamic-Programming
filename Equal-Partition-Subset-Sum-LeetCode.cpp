// Equal Partition SubSet Sum - LeetCode
// Given a non-empty array containing only positive integers,
// find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:

	bool subsetSum(vector <int> &v, int sum){

		int n = v.size();

		int dp[n+1][sum+1];

		for(int i=0;i<=n;i++) dp[i][0] = true;
		for(int i=1;i<=sum;i++) dp[0][i] = false;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=sum;j++){
				if(dp[i-1][j] == true) dp[i][j] = true;
				else{
					if(v[i-1] > j) dp[i][j] = false;
					else dp[i][j] = dp[i-1][j-v[i-1]];
				}
			}
		}
		return dp[n][sum];
	}

	bool canPartition(vector<int>& nums){

		int sum = 0;

		for(auto it: nums) sum += it;

		if(sum & 1) return false;
		else return subsetSum(nums, sum / 2);
	}
};