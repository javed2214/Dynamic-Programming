// SUPW Problem (Codechef)
// Dynamic Programming Problem

#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;

	int a[n];
	for(int i=1;i<=n;i++) cin>>a[i];

	for(int i=n-3;i>=0;i--)
		a[i]+=min(a[i+1], min(a[i+2], a[i+3]));

	int p=min(n,3);
	int mi=INT_MAX;

	for(int i=1;i<=p;i++)
		mi=min(mi,a[i]);

	cout<<mi;

	return 0;
}