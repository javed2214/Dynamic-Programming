// https://www.spoj.com/problems/EDIST/

#include<bits/stdc++.h>
using namespace std;

int editDistane(string s1, string s2, int l1, int l2){

	int dp[l1+1][l2+1];
	for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			if(i==0) dp[i][j]=j;
			else if(j==0) dp[i][j]=i;
			else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
		}
	}
	return dp[l1][l2];
}

int main(){

	int test;
	cin>>test;
	while(test--){
		string s1,s2;
		cin>>s1;
		cin>>s2;
		int l1=s1.length();
		int l2=s2.length();

		cout<<editDistane(s1,s2,l1,l2)<<endl;
	}

	return 0;
}