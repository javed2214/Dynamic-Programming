// Ilya And Queries (Codeforces)
// https://codeforces.com/contest/313/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	string str;
	cin>>str;
	ll n=str.length();
	ll dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<str.length();i++){
		if(str[i]==str[i-1]) dp[i]=dp[i-1]+1;
		else dp[i]=dp[i-1];
	}
	ll p,l,r;
	cin>>p;

	for(int i=0;i<p;i++){
		cin>>l>>r;
		cout<<dp[r-1]-dp[l-1];
		cout<<endl;
	}
	return 0;
}