// Best time to Buy and Sell Stock Problem III - LeetCode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {

public:

    int maxProfit(vector<int>& prices) {
        
        int buyFirst = INT_MAX;
        int sellFirst = 0;
        int buySecond = INT_MAX;
        int sellSecond = 0;
        
        for(auto it:prices){
            
            buyFirst = min(buyFirst, it);
            sellFirst = max(sellFirst, it - buyFirst);
            buySecond = min(buySecond, it - sellFirst);
            sellSecond = max(sellSecond, it - buySecond);
        }
        
        return sellSecond;
    }
};