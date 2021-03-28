// Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        if(n == 0 or n == 1) return s;
        int dp[n][n];
        int cnt = 0, mx = INT_MIN;
        string st;
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j) dp[i][j] = 1;
                else if(i + 1 == j){
                    if(s[i] == s[j]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else{
                    if(s[i] == s[j] and dp[i+1][j-1] == 1) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                if(dp[i][j] and j - i + 1 > mx){
                    mx = j - i + 1;
                    st = s.substr(i, j-i+1);
                }
            }
        }
        
        return st;
    }
};