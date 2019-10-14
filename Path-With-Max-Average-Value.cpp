// Path With Maximum Average Value
// https://www.geeksforgeeks.org/path-maximum-average-value/

#include<bits/stdc++.h>
using namespace std;

#define M 3

double maxAveragePath(int a[M][M], int n){

	int dp[n][n];

	dp[0][0] = a[0][0];

	for(int i=1;i<n;i++) dp[i][0] = dp[i-1][0] + a[i][0];
	for(int i=1;i<n;i++) dp[0][i] = dp[0][i-1] + a[0][i];

	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++)
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
	}

	return (double) dp[n-1][n-1] / (2 * n - 1);
}

int main(){

	int a[M][M] = {

		{1,2,3},
		{6,5,4},
		{7,3,9}
	};

	cout << maxAveragePath(a,M);

	return 0;
}