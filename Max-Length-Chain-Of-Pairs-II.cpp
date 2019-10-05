// Max Length of Chain of Pairs - LeetCode
// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
        
        sort(v.begin(), v.end());
        
        int n = v.size();
        
        vector<int> dp(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i][0] > v[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};