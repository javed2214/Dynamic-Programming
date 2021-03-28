// Longest Palindromic Subsequence
// https://www.youtube.com/watch?v=wuOOOATz_IA&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=26
// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    
    int LCS(string s1, string s2){
        
        int n1 = s1.size();
        int n2 = s2.size();
        
        int dp[n1+1][n2+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
    
    int longestPalindromeSubseq(string s) {
        
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        
        return LCS(s1, s2);
    }
};