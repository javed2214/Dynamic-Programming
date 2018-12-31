// Program to find Length of Longest Increasing Subsequene using DP

#include<bits/stdc++.h>
using namespace std;

int LIS(int *a, int n, int *dp){
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j])
				dp[i]=max(dp[i], dp[j]+1);
		}
	}
	return *max_element(dp, dp+n);
}

int main(){
	int a[]={4,5,2,6,9,8,12,15,17,19,26,45,67,89};
	int n=sizeof(a)/sizeof(int);
	int dp[n];
	for(int i=0;i<n;i++)
		dp[i]=1;
	cout<<LIS(a,n,dp);

	return 0; 
}