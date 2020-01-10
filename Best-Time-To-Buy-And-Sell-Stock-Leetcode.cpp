// Best Time to Buy and Sell Stock - LeetCode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://www.youtube.com/watch?v=mj7N8pLCJ6w

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0) return 0;
        
        int mx = INT_MIN, mi = INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            mi = min(mi, prices[i]);
            mx = max(mx, prices[i] - mi);
        }
        return mx;
    }
};
