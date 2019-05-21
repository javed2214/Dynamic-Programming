// Sereja and Suffixes (Codeforces)
// https://codeforces.com/contest/368/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll n,m;
	cin>>n>>m;
	ll a[n];
	unordered_map<ll,bool> Map;
	for(int i=0;i<n;i++) cin>>a[i], Map[a[i]]=true;
	ll dp[n];
	memset(dp,0,sizeof(dp));
	for(int i=n-1;i>=0;i--){
		if(i==n-1){
			dp[i]=1;
			Map[a[i]]=false;
		}
		else{
			if(Map[a[i]]==true){
				dp[i]=dp[i+1]+1;
				Map[a[i]]=false;
			}
			else dp[i]=dp[i+1];
		}
	}
	for(int i=0;i<m;i++){
		ll x;
		cin>>x;
		cout<<dp[x-1];
		cout<<endl;
	}
	return 0;
}
