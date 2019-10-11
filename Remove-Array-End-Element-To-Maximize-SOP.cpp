// Remove Array End Element to Maximize the Sum of Product - (Dynamic Programming)
// 

#include<bits/stdc++.h>
using namespace std;
#define MAX 101

int maxSum(int *a, int dp[][MAX], int low, int high, int step){

	if(low == high) return a[low] * step;

	if(dp[low][high] != 0) return dp[low][high];

	dp[low][high] = max(a[low]*step + maxSum(a,dp,low+1,high,step+1), a[high]*step + maxSum(a,dp,low,high-1,step+1));

	return dp[low][high];
}

int main(){

	int a[] = {1, 3, 1, 5, 2};
	int n = sizeof(a) / sizeof(int);

	int dp[MAX][MAX];

	memset(dp,0,sizeof(dp));

	cout << maxSum(a,dp,0,n-1,1);

	return 0;
}