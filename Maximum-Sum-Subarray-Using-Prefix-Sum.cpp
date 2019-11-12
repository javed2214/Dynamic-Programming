// Maximum Sum Subarray Using Prefix Sum
// https://www.geeksforgeeks.org/maximum-subarray-sum-using-prefix-sum/

#include<bits/stdc++.h>
using namespace std;

int main(){

	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a) / sizeof(int);

	int prefix[n];

	prefix[0] = a[0];

	for(int i=1;i<n;i++)
		prefix[i] = prefix[i-1] + a[i];

	int mi = 0, mx = INT_MIN;

	for(int i=0;i<n;i++){
		mx = max(mx, prefix[i] - mi);
		mi = min(mi, prefix[i]);
	}

	cout << mx;

	return 0;
}