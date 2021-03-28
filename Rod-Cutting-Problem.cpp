// Rod Cutting Problem
// https://www.youtube.com/watch?v=SZqAQLjDsag&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=14

#include<bits/stdc++.h>
using namespace std;

// =============================== METHOD - 1 =======================================
int rodCutting1(int *price, int n){

	int length[n];
	for(int i = 0; i < n; i++) length[i] = i+1;

	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(length[i-1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-length[i-1]]);
		}
	}
	return dp[n][n];
}

// =============================== METHOD - 2 =======================================
int rodCutting2(int *price, int n){

	int length[n];
	for(int i = 0; i < n; i++) length[i] = i+1;

	int dp[n+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n; j++){
			if(length[j] <= i) dp[i] = max(dp[i], price[j] + dp[i-length[j]]);
		}
	}
	return dp[n];
}

int main(){

	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(price) / sizeof(int);	// Length of the Rod

	cout << rodCutting2(price, n);

	return 0;
}