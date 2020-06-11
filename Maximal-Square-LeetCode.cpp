// Maximal Square - LeetCode
// https://leetcode.com/problems/maximal-square/
// https://www.youtube.com/watch?v=BE_gwjrBPMs   -  Best Explanation

// *** METHOD 1 ***
class Solution {
public:
    
    int n, m;
    unordered_map <string, int> Map;
    
    int go(vector <vector<char>> &mat, int x, int y){
        
        if(x >= n or y >= m or mat[x][y] == '0') return 0;
        string s = to_string(x) + "|" + to_string(y);
        if(Map.count(s)) return Map[s];
        int sum = 1 + min(go(mat, x + 1, y + 1), min(go(mat, x + 1, y), go(mat, x, y + 1)));
        return Map[s] = sum;
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        if(mat.size() == 0) return 0;
        n = mat.size();
        m = mat[0].size();
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mx = max(mx, go(mat, i, j));
            }
        }
        return mx * mx;
    }
};


// *** METHOD 2 ***
class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        
        if(mat.size() == 0) return 0;
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int mx = 0, s = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!i or !j or mat[i][j] == '0') dp[i][j] = mat[i][j] - '0';
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                mx = max(dp[i][j], mx);
            }
        }
        return mx * mx;
    }
};