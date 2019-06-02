// Fence Codeforces

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	ll preSum[n];
	for(int i=0;i<n;i++){
		if(i==0) preSum[i]=a[i];
		else preSum[i]=preSum[i-1]+a[i];
	}
	ll p=0,mi=preSum[k-1],x=1,j=2;
	for(int i=k;i<n;i++){
		if(preSum[i]-preSum[p] < mi){
			mi=(preSum[i]-preSum[p]);
			x=j;
		}
		++p;
		j++;
	}
	// cout<<mi<<endl;
	cout<<x;
}

// 3 1 4 1 4 6 2 1 4 6
// 3 4 8 9 13 19 21 22 26 32