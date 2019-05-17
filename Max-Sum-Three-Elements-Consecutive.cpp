// Maximum Sum such that No Three Elements are Consecutive

#include<bits/stdc++.h>
using namespace std;

int main(){

	int a[]={1,2,3,4,5};
	int n=sizeof(a)/sizeof(int);

	int sum[n];

	sum[0]=a[0];
	sum[1]=a[0]+a[1];
	sum[2]=max(a[0]+a[1], max(a[1]+a[2], a[0]+a[2]));

	// sum[i-1] -> Excluding a[i]
	// sum[i-2]+a[i] -> Excluding a[i-1]
	// sum[i-3]+a[i-1]+a[i-2] -> Excluding a[i-2]

	for(int i=3;i<n;i++)
		sum[i]=max(sum[i-1], max(sum[i-2]+a[i], sum[i-3]+a[i-1]+a[i]));

	cout<<sum[n-1];

	return 0;
}