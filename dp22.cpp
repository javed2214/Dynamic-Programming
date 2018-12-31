// Given two strings str1 and str2 and below operations that can performed on str1.
// Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
// Insert
// Remove
// Replace
// All of the above operations are of equal cost. (DP)

#include<bits/stdc++.h>
using namespace std;

int editString(string str1,string str2,int m,int n){
	int dp[m+1][n+1];

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
		}
	}
	return dp[m][n];
}
int main(){
	string str1="sunday";
	string str2="saturday";
	int m=str1.length();
	int n=str2.length();

	cout<<editString(str1,str2,m,n);

	return 0;
}