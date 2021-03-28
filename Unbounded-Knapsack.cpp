// Unbounded Knapsack Problem
// https://www.youtube.com/watch?v=jgps7MXtKRQ

#include<bits/stdc++.h>
using namespace std;

// ==================================== METHOD - 1 ==========================================
int unboundedKnapsack1(int *wt, int *val, int W, int n){

	int dp[W+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i <= W; i++)
		for(int j = 0; j < n; j++)
			if(wt[j] <= i)
				dp[i] = max(dp[i], val[j] + dp[i-wt[j]]);

	return dp[W];
}

// ==================================== METHOD - 2 ==========================================
int unboundedKnapsack2(int *wt, int *val, int W, int n){

	int dp[n+1][W+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i][j-wt[i-1]]);
		}
	}
	return dp[n][W];
}

int main(){

	int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);
 
    cout << unboundedKnapsack2(wt, val, W, n);

    return 0;
}