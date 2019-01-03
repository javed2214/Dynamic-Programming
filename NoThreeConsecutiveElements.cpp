// Program to find Max Sum such that No Three Elements are Consecutive

#include<bits/stdc++.h>
using namespace std;

int maxThree(int *a, int n){
	int sum[n];
	if(n>=1)
		sum[0]=a[0];
	if(n>=2)
		sum[1]=a[0]+a[1];
	if(n>2)
		sum[2]=max(sum[1], max(a[0]+a[2], a[1]+a[2]));
	for(int i=3;i<n;i++)
		sum[i]=max(sum[i-1], max(sum[i-2]+a[i], sum[i-3]+a[i-1]+a[i]));

	return sum[n-1];
}

int main(){
	int a[]={1,2,3,4,5,6,7};
	int n=sizeof(a)/sizeof(int);

	cout<<maxThree(a,n);

	return 0;
}

// OUTPUT ==>> 21
