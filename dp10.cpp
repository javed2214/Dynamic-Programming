// Rod Cutting Problem (Recursion + Memoization)

#include<bits/stdc++.h>
using namespace std;

int rodCutting(int n, int *val, int *dp){
	if(n==0) 
		return 0;
	if(dp[n-1]!=-1)
		return dp[n-1];

	int x=-1;

	for(int i=0;i<n;i++){
		x=max(x, val[i]+rodCutting(n-i-1, val, dp));
		dp[n-1]=x;
	}
	return dp[n-1];
}
int main(){
	int val[]={1,5,8,9,10};
	int n=sizeof(val)/sizeof(int);
	int dp[n];
	for(int i=0;i<n;i++)
		dp[i]=-1;
	cout<<rodCutting(5,val,dp);
	
	return 0;
}