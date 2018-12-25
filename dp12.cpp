// Minimum Steps To One Problem. Can Perform only Following Operations
// If n is divisible by 2 then we may reduce n to n/2.
// If n is divisible by 3 then you may reduce n to n/3.
// Decrement n by 1.

#include<bits/stdc++.h>
using namespace std;

int minSteps(int n, int *dp){
	if(n==1)
		return 0;
	if(dp[n]!=-1)
		return dp[n];
	int r=minSteps(n-1, dp);
	if(n%2==0)
		r=min(r, minSteps(n/2, dp));
	if(n%3==0)
		r=min(r, minSteps(n/3, dp));
	dp[n]=1+r;
	return dp[n];
}

int main(){
	int n=10;
	int dp[n+1];
	for(int i=0;i<=n;i++)
		dp[i]=-1;
	cout<<minSteps(n,dp);

	return 0;
}
// OUTPUT ==>> 3