// Smart Phone Problem (Codechef)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll n;
	cin>>n;

	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];

	sort(a,a+n,greater<ll>());
	for(int i=0;i<n;i++) a[i]=a[i]*(i+1);
	cout<<*max_element(a,a+n);

	return 0;
}