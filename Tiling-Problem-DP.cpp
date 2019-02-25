// Tiling Problem - Dynamic Programming
// https://www.youtube.com/watch?v=ucbH-tga7U4
// Number of ways to Fill the Board of 2*n size with Tiles of size 1*2
// Fibbonacci Series

#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int *dp=new int[n+1];
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];

	cout<<dp[n];

	return 0;
}