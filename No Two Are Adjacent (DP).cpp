// Program to Find Max Sum such that No Two Elements are Adjacent to Each Other using DP

#include<bits/stdc++.h>
using namespace std;

/*

int dp[n];
dp[0]=9;dp[1]=3;

for(int i=2;i<n;i++)
	dp[i]=max(a[i]+dp[i-2], dp[i-1]);

cout<<dp[n-1];

*/

int findMax(int *a, int n){
	int incl, excl, x;
	incl=a[0];
	excl=0;
	for(int i=1;i<n;i++){
		x=max(incl, excl);
		incl=excl+a[i];
		excl=x;
	}
	return max(incl, excl);
}

int main(){
	int a[]={9,3,1,6,8,9,7,4};
	int n=sizeof(a)/sizeof(int);
	cout<<findMax(a,n);

	return 0;
}
// OUTPUT ====>> 28
