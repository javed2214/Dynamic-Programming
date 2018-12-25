// 0/1 Knapsack Problem using Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

int knapsack(int *val, int *wt, int cap, int n){
	int dp[n+1][cap+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=cap;j++){
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(wt[i-1]<=j)
				dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][cap];
}

int main(){

	int val[]={20,40,70,30,60};
	int wt[]={1,2,3,4,5};
	int n=sizeof(wt)/sizeof(int);
	int cap=4;
	cout<<knapsack(val,wt,cap,n);

	return 0;
}