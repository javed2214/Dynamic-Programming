// Flipping Game (Codeforces)
// https://codeforces.com/contest/327/problem/A

#include<bits/stdc++.h>
using namespace std;

int main(void){

	int n,x,c=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>x;
		if(x==0) a[i]=1;
		else a[i]=-1,c++;
	}
	
	int sum=0,mx=INT_MIN;

	for(int i=0;i<n;i++){
		sum+=a[i];
		mx=max(mx,sum);
		if(sum<0) sum=0;
	}
	cout<<mx+c;

	return 0;
}
