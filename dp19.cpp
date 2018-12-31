// Program to Print Fibonacci Series in Reverse Order

#include<bits/stdc++.h>
using namespace std;

int fib(int n, int *dp){
	if(n==0 || n==1){
		dp[n]=n;
		return dp[n];
	}
	if(dp[n]!=-1)
		return dp[n];
	
	return dp[n]=fib(n-1, dp) + fib(n-2, dp);
}

int main(){
	int n=10;
	int dp[100];
	for(int i=0;i<100;i++)
		dp[i]=-1;
	fib(n,dp);
	for(int i=9;i>=0;i--)
		cout<<dp[i]<<" ";
	return 0;
}