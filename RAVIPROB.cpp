// Ravi Shankar and the Problem (Codechef)
// https://www.codechef.com/problems/RAVIPROB

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll test;
	cin>>test;

	while(test--){

		ll a,b,p,q,s=1;
		cin>>a>>b;
		ll xx[b];
		p=a/b;
		q=a%b;
		for(int i=0;i<b;i++) xx[i]=p;
		ll i=0;
		while(q--) xx[i++]++;
		for(int i=0;i<b;i++) s*=xx[i];
		cout<<s<<endl;
	}
	return 0;
}