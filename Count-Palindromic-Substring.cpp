// Count Palindromic Substring (Special Problem)
// https://www.youtube.com/watch?v=XmSOWnL6T_I&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=6
// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size();
        int dp[n][n], cnt = 0;
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j) dp[i][j] = 1;
                else if(i+1 == j){
                    if(s[i] == s[j]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else{
                    if(s[i] == s[j] and dp[i+1][j-1] == 1) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};