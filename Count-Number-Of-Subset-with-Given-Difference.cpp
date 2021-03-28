// Count Number of Subset with Given Difference
// https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11

#include<bits/stdc++.h>
using namespace std;

int countSubset(int *a, int n, int diff){

	// subset1_sum - subset2_sum = diff   -------(1)
	// subset1_sum + subset2_sum = sum    -------(2)
	// Adding (1) and (2)
	// 2 * subset1_sum = sum + diff
	// subset1_sum = (sum + diff) / 2

	int sum = 0;
	for(int i = 0; i < n; i++) sum += a[i];

	int subset1_sum = (sum + diff) / 2;
	
	// Now, we just need to count the subset having sum equal to subset1_sum

	int dp[n+1][subset1_sum+1];

	for(int i = 0; i <= n; i++) dp[i][0] = 1;
	for(int j = 1; j <= subset1_sum; j++) dp[0][j] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= subset1_sum; j++){
			if(a[i-1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
		}
	}
	return dp[n][subset1_sum];
}

int main(){

	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	int diff; cin >> diff;

	cout << countSubset(a, n, diff);

	return 0;
}