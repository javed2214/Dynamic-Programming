// Length of Shortest Common Supersequence
// https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=24

#include<bits/stdc++.h>
using namespace std;

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

int main(){

	string s1, s2;
	cin >> s1 >> s2;

	int lcs = LCS(s1, s2);   // Longest Common Subsequence

	int superSequence = (s1.size() + s2.size()) - lcs;

	cout << superSequence;

	return 0;
}