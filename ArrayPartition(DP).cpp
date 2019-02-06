// Array Partition Problem (DP Approach)
// Program to Find Whether the Array Partition is Possible in Two Equal Sums or Not
// https://www.geeksforgeeks.org/partition-problem-dp-18/

#include<bits/stdc++.h>
using namespace std;

bool cal(int *a, int n, int sum){

	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
		dp[i][0]=true;
	for(int j=1;j<=sum;j++)
		dp[0][j]=false;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(a[i-1]>j)
				dp[i][j]=dp[i-1][j];
			else if(a[i-1]<=j)
				dp[i][j]=dp[i-1][j] or dp[i-1][j-a[i-1]];
		}
	}
	return dp[n][sum];
}

int main(){
	
	int a[]={1,5,3,3};
	int n=sizeof(a)/sizeof(int);
	int sum=0;
	for(auto i:a)
		sum+=i;

	if(sum&1){
		cout<<"No";
		return 0;
	}
	else{
		if(cal(a,n,sum/2)==1) cout<<"Yes";
		else cout<<"No";
	}

	return 0;
}
