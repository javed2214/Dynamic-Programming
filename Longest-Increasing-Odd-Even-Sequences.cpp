// Longest Increasing Odd Even Sequences
// https://www.geeksforgeeks.org/longest-increasing-odd-even-subsequence/

#include<bits/stdc++.h>
using namespace std;

int oddEven(int *a, int n){

	int dp[n];

	for(int i=0;i<n;i++) dp[i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i] > a[j] and (a[i] + a[j]) % 2 != 0)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	return *max_element(dp, dp + n);
}

int main(){

	int a[] = {1, 12, 2, 22, 5, 30, 31, 14, 17, 11};
	int n = sizeof(a) / sizeof(int);

	cout << oddEven(a,n);

	return 0;
}