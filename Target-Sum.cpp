// Target Sum (LeetCode)
// https://leetcode.com/problems/target-sum/
// https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12

// ================================== METHOD - 1 =========================================

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int sum = 0, cnt = 0;
        for(auto it: nums){
            sum += it;
            if(it == 0) cnt += 1;
        }
        
        if(S > sum) return 0;
        if((S + sum) % 2 != 0) return 0;
        
        int subset1_sum = (S + sum) / 2;
        
        int n = nums.size();
        
        int dp[n+1][subset1_sum+1];
        
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int j = 1; j <= subset1_sum; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= subset1_sum; j++){
                if(nums[i-1] == 0) dp[i][j] = dp[i-1][j];
                else if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return pow(2, cnt) * dp[n][subset1_sum];
    }
};


// ================================== METHOD - 2 =========================================

class Solution {
public:
    
    map <pair<int, int>, int> Map;
    
    int targetSum(vector<int> &nums, int S, int index, int cur_sum){
        
        if(index < 0 and cur_sum == S) return 1;
        if(index < 0) return 0;
        
        if(Map.find({index, cur_sum}) != Map.end()) return Map[{index, cur_sum}];
        
        int positive = targetSum(nums, S, index - 1, cur_sum + nums[index]);
        int negative = targetSum(nums, S, index - 1, cur_sum - nums[index]);
        
        return Map[{index, cur_sum}] = positive + negative;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int index = nums.size() - 1;
        int cur_sum = 0;
        return targetSum(nums, S, index, cur_sum);
    }
};