// Program to Find Length of Longest Bitonic Subsequence
// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
// LBS = max(LIS + LDS - 1)

#include<bits/stdc++.h>
using namespace std;

int LBS(int *a, int n){

	int lis[n];

	for(int i=0;i<n;i++) lis[i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i] > a[j] and lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
	}

	int lds[n];

	for(int i=0;i<n;i++) lds[i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i] < a[j] and lds[i] < lds[j] + 1)
				lds[i] = lds[j] + 1;
		}
	}

	int mx = -1;

	for(int i=0;i<n;i++)
		mx = max(mx, lis[i] + lds[i] - 1);

	return mx;
}

int main(){

	int a[] = {80,60,30,40,20,10};
	int n = sizeof(a) / sizeof(int);

	cout<<LBS(a,n);

	return 0;
}