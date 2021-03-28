// Minimum Number of Insertion to make String Palindrome
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// https://www.youtube.com/watch?v=AEcRW4ylm_c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=32

// Same as "Min No of Deletion to make String Palindrome"

#include<bits/stdc++.h>
using namespace std;

int LPS(string s1, string s2){

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

int main(){

	string s;
	cin >> s;

	string s1 = s;
	reverse(s.begin(), s.end());
	string s2 = s;

	int lps = LPS(s1, s2);  // Longest Palindromic Subsequence

	int minInsertion = s.size() - lps;

	cout << minInsertion;

	return 0;
}