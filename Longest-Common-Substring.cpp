// Longest Common Substring
// Using Dynamic Programming
// Variant of Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2){

    int n = s1.length();
    int m = s2.length();

    int dp[n+1][m+1];
    int res = 0;

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 0; i <= m; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                res  = max(res, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return res;
}

int main(){

    string s1 = "geeksx";
    string s2 = "forgeeksz";

    cout << LCS(s1, s2);

    return 0;
}