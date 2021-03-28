// Minimum Subset Sum Difference
// Partition a set into two subsets such that the difference of subset sums is minimum
// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
// https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10

/*
Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11
Min Diff: 12 - 11 = 1  
*/

#include<bits/stdc++.h>
using namespace std;

int subsetSumDiff(int *a, int n){

	int sum = 0;
	for(int i = 0; i < n; i++) sum += a[i];

	bool dp[n+1][sum+1];

	for(int i = 0; i <= n; i++) dp[i][0] = true;
	for(int j = 1; j <= sum; j++) dp[0][j] = false;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(a[i-1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
		}
	}

	int mi = INT_MAX;

	for(int j = 0; j <= sum / 2; j++){
		if(dp[n][j] == true)
			mi = min(mi, sum - 2 * j);
	}
	return mi;
}

int main(){

	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	cout << subsetSumDiff(a, n);

	return 0;
}