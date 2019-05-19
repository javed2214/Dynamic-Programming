// BOREDOM Codeforces
// https://codeforces.com/problemset/problem/455/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	ll cnt[100005];
	ll dp[100005];

	memset(cnt,0,sizeof(cnt));

	for(int i=0;i<n;i++)
		cnt[a[i]]++;

	dp[0]=0;
	dp[1]=cnt[1];

	for(int i=2;i<=100000;i++)
		dp[i]=max(dp[i-1], dp[i-2] + cnt[i]*i*1LL);

	cout<<dp[100000];
	cout<<endl;

	return 0;
}