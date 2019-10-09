// Minimum Steps to Minimize n to 1 as Per Given Condition

// Given a number n, count minimum steps to minimize it to 1 according to the following criteria:

// If n is divisible by 2 then we may reduce n to n/2.
// If n is divisible by 3 then you may reduce n to n/3.
// Decrement n by 1.

// f(n) = 1 + f(n-1)
// f(n) = 1 + f(n/2)   if n is divisible by 2
// f(n) = 1 + f(n/3)   if n is divisible by 3

#include<bits/stdc++.h>
using namespace std;

int getMinSteps(int n, int *dp){

	if(n == 1) return 0;
	if(dp[n] != -1) return dp[n];

	int res = getMinSteps(n-1, dp);
	if(n % 2 == 0) res = min(res, getMinSteps(n/2, dp));
	if(n % 3 == 0) res = min(res, getMinSteps(n/3, dp));

	dp[n] = 1 + res;

	return dp[n];
}

int main(){

	int n;
	cin >> n;

	int dp[n+1];

	for(int i=0;i<=n;i++) dp[i] = -1;

	cout << getMinSteps(n, dp);

	return 0;
}