// Subset Sum Problem using Dynamic Programming
// Variation of 0/1 Knapsack Problem

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int *a, int n, int sum){

	bool dp[n+1][sum+1];

	for(int i = 0; i <= n; i++) dp[i][0] = true;
	for(int j = 1; j <= sum; j++) dp[0][j] = false;

	// dp[0][0] is true, because we can make sum 0 by not including any array elements
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(a[i-1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] or dp[i-1][j-a[i-1]];
		}
	}
	if(dp[n][sum]) return true;
	else return false;
}	

int main(){
	int a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(int);
	int sum=15;
	bool x=subsetSum(a,n,sum);
	if(x)
		cout<<"Yes";
	else
		cout<<"No";

	return 0;
}
