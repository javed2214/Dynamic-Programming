// Program to Find Length of Lonest Palindromic Subsequence Using Dynamic Programming
// https://leetcode.com/problems/longest-palindromic-subsequence/

#include<bits/stdc++.h>
using namespace std;

int METHOD_1 (string s){

	int n = s.size();
	if(n < 2) return n;

	vector <vector<int>> dp(n+1, vector<int> (n+1));
	string rev = s;
	reverse(rev.begin(), rev.end());

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1] == rev[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][n];
}

int main(){

	string s;
	cin>>s;

	cout << METHOD_1(s);

	return 0;
}