// Longest Common Substring
// Variation of Longest Common Subsequence

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
			else dp[i][j] = 0;   // For Subsequence: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
		}
	}
	return dp[n1][n2];
}

int main(){

	string s1, s2;
	cin >> s1 >> s2;

	cout << LCS(s1, s2);

	return 0;
}