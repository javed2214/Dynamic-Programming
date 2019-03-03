// Program to Count Number of Binary Search Trees that Can be Formed by Given 'n' Keys
// https://www.youtube.com/watch?v=kT_VabdscHk
// Application of Dynamic Programming
// Catalan Numbers

#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int *dp=new int[n+1];
	dp[0]=dp[1]=1;

	for(int i=2;i<=n;i++){
		dp[i]=0;
		for(int j=0;j<i;j++)
			dp[i]+=dp[j]*dp[i-j-1];
	}
	cout<<dp[n];

	return 0;
}