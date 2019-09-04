// Program to Find Length of Longest Decreasing Subsequence
// https://www.geeksforgeeks.org/longest-decreasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

int LDS(int *a, int n){

	int lds[n];

	for(int i=0;i<n;i++) lds[i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i] < a[j] and lds[i] < lds[j] + 1)
				lds[i] = lds[j] + 1;
		}
	}
	return *max_element(lds, lds + n);
}

int main(){

	int a[] = {15, 27, 14, 38, 63, 55, 46, 65, 85};
	int n = sizeof(a) / sizeof(int);

	cout<<LDS(a,n);

	return 0;
}