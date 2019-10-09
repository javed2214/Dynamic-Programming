// Minimum Cost to Make Two Strings Identical
// https://www.geeksforgeeks.org/minimum-cost-make-two-strings-identical/

// Good Question!!!

// Given two strings X and Y, and two values costX and costY. 
// We need to find minimum cost required to make the given two strings identical. 
// We can delete characters from both the strings. The cost of deleting a character from string X is costX and from Y is costY.
// Cost of removing all characters from a string is same.

#include<bits/stdc++.h>
using namespace std;

int LCA(string s1, int n1, string s2, int n2){

	int dp[n1+1][n2+1];

	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			if(i == 0 or j == 0) dp[i][j] = 0;
			else if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n1][n2];
}

int minCost(string s1, string s2, int cost1, int cost2){

	int n1 = s1.length();
	int n2 = s2.length();

	int lca = LCA(s1,n1,s2,n2);

	int min_cost = cost1 * (n1 - lca) + cost2 * (n2 - lca);

	return min_cost; 
}

int main(){

	string s1, s2;
	cin>>s1>>s2;

	int cost1, cost2;
	cin>>cost1>>cost2;

	cout << minCost(s1,s2,cost1,cost2);

	return 0;
}