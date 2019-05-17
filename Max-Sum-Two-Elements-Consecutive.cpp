// Max Sum such the No Two Elements are Consecutive

#include<bits/stdc++.h>
using namespace std;

int main(){

	int a[]={5,5,10,100,10,5};
	int n=sizeof(a)/sizeof(int);

	int sum[n];

	if(n>=0) sum[0]=a[0];
	if(n>=1) sum[1]=max(a[0],a[1]);

	// sum[i]=sum[i-1] -> Excluding Current Element
	// sum[i]=sum[i-2]+a[i] -> Including Current Elment

	for(int i=2;i<n;i++)
		sum[i]=max(sum[i-1],sum[i-2]+a[i]);

	cout<<sum[n-1];

	return 0;
}