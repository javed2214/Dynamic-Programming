// Longest Common Subsequence of Three Strings
// https://www.geeksforgeeks.org/lcs-longest-common-subsequence-three-strings/

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, int n1, string s2, int n2, string s3, int n3){

	int dp[n1+1][n2+1][n3+1];

	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			for(int k=0;k<=n3;k++){
				if(i == 0 or j == 0 or k == 0) dp[i][j][k] = 0;
				else if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]) dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
				else dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
			}
		}
	}
	return dp[n1][n2][n3];
}

int main(){

	string s1 = "AGGT12"; 
    string s2 = "12TXAYB"; 
    string s3 = "12XBA"; 

    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    cout << LCS(s1,n1,s2,n2,s3,n3);

    return 0;
}