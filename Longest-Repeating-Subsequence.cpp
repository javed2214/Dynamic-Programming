// Longest Repeating Subsequence
// Variation of Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;

int LRS(string s){

	int n = s.size();

	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(s[i-1] == s[j-1] and i != j) dp[i][j] =  1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][n];
}

int main(){

	string s;
	cin >> s;

	cout << LRS(s);

	return 0;
}