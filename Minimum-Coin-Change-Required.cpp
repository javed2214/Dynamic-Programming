// Minimum Coin Change Required Problem (LeetCode)
// https://leetcode.com/problems/coin-change/
// https://www.youtube.com/watch?v=jgiZlGzXMBw	[Best Explanation on Youtube]

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector <int> v(amount+1, amount+1);
        v[0] = 0;
        
        for(int i=1;i<amount+1;i++)
            for(int j=0;j<coins.size();j++)
                if(coins[j] <= i) v[i] = min(1 + v[i-coins[j]], v[i]);
            
        return v[amount] != (amount + 1) ? v[amount] : -1;
    }
};
