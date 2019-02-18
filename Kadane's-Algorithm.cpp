// Kadane's Algorithm to Find Maximum Sum Contiguous SubArray
// Ex: [-2,1,-3,4,-1,2,1,-5,4] => [4,-1,2,1] Ans=6

#include<bits/stdc++.h>
using namespace std;

int main(){

	int a[]={-2,1,-3,4,-1,2,1,-5,4};
	int n=sizeof(a)/sizeof(int);

	int sum=0,mx=INT_MIN;

	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum>mx) mx=sum;
		if(sum<0) sum=0;
	}
	cout<<mx;

	return 0;
}