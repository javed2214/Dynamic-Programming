// ----- Author: Javed Ansari -----
// http://codeforces.com/problemset/problem/189/A

#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MOD 1000000007
#define DB(x) cout<<#x<<"="<<x<<endl;
#define FASTREAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define SIZE 100000000

ll n,a,b,c;
int *dp=new int[4001];

int solveDP(ll n){

	if(n==0) return 0;
	else if(n<0) return INT_MIN;
	else if(dp[n]!=-1) return dp[n];
	else dp[n]=1+max(solveDP(n-a),max(solveDP(n-b),solveDP(n-c)));
	return dp[n];
}

int main(){

	cin>>n>>a>>b>>c;
	for(int i=0;i<4001;i++) dp[i]=-1;
	cout<<solveDP(n);

	return 0;
}
