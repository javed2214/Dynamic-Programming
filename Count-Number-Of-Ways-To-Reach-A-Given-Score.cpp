// Count Number of Ways to Reach a Given Score in a Game
// https://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/

#include<bits/stdc++.h>
using namespace std;

int countWays(int n){

	int dp[n+1];

	memset(dp, 0, sizeof dp);

	dp[0] = 1;

	for(int i=3;i<=n;i++) dp[i] += dp[i-3];
	for(int i=5;i<=n;i++) dp[i] += dp[i-5];
	for(int i=10;i<=n;i++) dp[i] += dp[i-10];

	return dp[n];
}

int main(){

	int n;
	cin>>n;

	cout << countWays(n);

	return 0;
}