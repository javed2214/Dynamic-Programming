// Minimum Cost Path - Dynamic Programming
// https://www.geeksforgeeks.org/min-cost-path-dp-6/

#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int minCost(int cost[R][C], int m, int n){

	int dp[R][C];

	dp[0][0] = cost[0][0];

	for(int i=1;i<R;i++) dp[i][0] = dp[i-1][0] + cost[i][0];
	for(int i=1;i<C;i++) dp[0][i] = dp[0][i-1] + cost[0][i];

	for(int i=1;i<R;i++)
		for(int j=1;j<C;j++)
			dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + cost[i][j];

	return dp[m][n];
}

int main(){

	int cost[R][C] = {
		{1,2,3},
		{4,8,2},
		{1,5,3}
	};

	cout << minCost(cost, 2, 2);

	return 0;
}