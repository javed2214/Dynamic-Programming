// Sum Triangle
// https://www.codechef.com/problems/SUMTRIAN
// Classical DP Problem

#include<bits/stdc++.h>
using namespace std;

int main(){

	ll n;
	cin>>n;
	ll a[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cin>>a[i][j];
		}
	}
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			a[i-1][j]=max(a[i][j], a[i][j+1])+a[i-1][j];
		}
	}
	cout<<a[0][0];
}