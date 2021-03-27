// Count of Subset with Sum Equal to X
// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

// Input: arr[] = {1, 2, 3, 3}, X = 6 
// Output: 3 
// All the possible subsets are {1, 2, 3}, {1, 2, 3} and {3, 3}

#include<bits/stdc++.h>
using namespace std;

int subsetSum(int *a, int n, int sum){

	int dp[n+1][sum+1];

	for(int i = 0; i <= n; i++) dp[i][0] = 1;
	for(int j = 1; j <= sum; j++) dp[0][j] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(a[i-1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
		}
	}
	return dp[n][sum];
}

int main(){

	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	int sum; cin >> sum;

	cout << subsetSum(a, n, sum);

	return 0;
}