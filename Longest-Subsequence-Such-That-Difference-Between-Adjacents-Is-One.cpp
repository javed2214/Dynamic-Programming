// Longest Subsequence Such that Difference Between Adjacents is One
// https://www.geeksforgeeks.org/longest-subsequence-such-that-difference-between-adjacents-is-one/

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int *a, int n){

	int dp[n];

	for(int i=0;i<n;i++) dp[i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(abs(a[i] - a[j]) == 1)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	return *max_element(dp, dp + n);
}

int main(){

	int a[] = {1, 2, 3, 2, 3, 7, 2, 1};
	int n = sizeof(a) / sizeof(int);

	cout << longestSubsequence(a,n);

	return 0;
}