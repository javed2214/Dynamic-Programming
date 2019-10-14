// Maximum Sum of Increasing Subsequence
// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

#include<bits/stdc++.h>
using namespace std;

int maxSumIS(int *a, int n){

	int dp[n];

	for(int i=0;i<n;i++) dp[i] = a[i];

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + a[i]);
		}
	}
	return *max_element(dp, dp+n);
}

int main(){

	int a[] = {1,101,2,3,100,4,5};
	int n = sizeof(a) / sizeof(int);

	cout << maxSumIS(a,n);

	return 0;
}