// Maximize the Sum of Selected Numbers to Make it Empty
// https://www.geeksforgeeks.org/maximize-sum-selected-numbers-performing-following-operation/

#include<bits/stdc++.h>
using namespace std;

int maxSum(int *a, int n){

	unordered_map <int,int> Map;

	for(int i=0;i<n;i++) Map[a[i]]++;

	int mx = *max_element(a, a + n);
	
	for(int i=2;i<=mx;i++)
		Map[i] = max(Map[i-1], Map[i-2] + Map[i] * i);

	return Map[mx];
}

int main(){

	int a[] = {1,2,3};
	int n = sizeof(a) / sizeof(int);

	cout << maxSum(a,n);

	return 0;
}