// Program to Print Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, int n1, string s2, int n2){

	int dp[n1+1][n2+1];	// Memoization Matrix

	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			if(i==0 or j==0)
				dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int i=n1,j=n2;
	string lcs="";
	string s;

	while(i>0 and j>0){

		if(s1[i-1]==s2[j-1]){
			s+=s1[i-1];
			lcs.insert(0,s);
			s.clear();
			i--;j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}
	cout<<"LCS: "<<lcs<<endl;

	return dp[n1][n2];
}

int main(){

	string s1="abcdefg";
	string s2="beftg";
	int n1=s1.size();
	int n2=s2.size();

	cout<<"Length: "<<LCS(s1,n1,s2,n2);

	return 0;
}
