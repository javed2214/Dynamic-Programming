// Tablet Problem (HackerEarth)
// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/tablets/description/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll n;
	cin>>n;
	ll a[n],dp[n];

	for(int i=0;i<n;i++) cin>>a[i],dp[i]=1;
	
	for(int i=1;i<n;i++){
		if(a[i] > a[i-1])
			dp[i]=dp[i-1]+1;
		else
			dp[i]=1;
	}
	for(int i=n-2;i>=0;i--){
		if(a[i] > a[i+1] and dp[i] <= dp[i+1])
			dp[i]=dp[i+1]+1;
	}

	ll sum=0;
	for(int i=0;i<n;i++) sum+=dp[i];

	cout<<sum;

	return 0;
}