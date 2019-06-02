// minimum Consecutive Sum of 'k' Elements
// a=[4 3 1 6 7 9 1 2 1] k=3  Output => 4 (Sum of 1 2 1)

#include<bits/stdc++.h>
using namespace std;

int main(){

	int a[]={4,3,1,6,7,9,1,2,1};
	int n=sizeof(a)/sizeof(int);
	int k=3;

	int preSum[n];

	for(int i=0;i<n;i++){
		if(i==0) preSum[i]=a[i];
		else preSum[i]=preSum[i-1]+a[i];
	}
	int p=0,mi=preSum[k-1];
	for(int i=k;i<n;i++){
		mi=min(mi,preSum[i]-preSum[p]);
		p++;
	}
	cout<<mi;
}