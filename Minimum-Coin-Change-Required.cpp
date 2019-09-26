// Minimum Coin Change Required Problem (LeetCode)
// https://leetcode.com/problems/coin-change/
// https://www.youtube.com/watch?v=jgiZlGzXMBw	[Best Explanation on Youtube]

class Solution {
public:
    int coinChange(vector<int>& coins, int amount){

    	vector <int> dp (amount + 1, amount + 1);	// Making dp[] array and filled with (amount + 1)
    	dp[0] = 0;

    	for(int i=0;i<=amount;i++){
    		for(int j=0;j<coins.size();j++){
    			if(coins[j] <= i)
    				dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
    		}
    	}
    	if(dp[amount] == (amount + 1)) return -1;
    	return dp[amount];
    }
};