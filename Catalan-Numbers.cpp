// Catalan Numbers
// https://www.youtube.com/watch?v=GgP75HAvrlY

/*

Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.
1) Count the number of expressions containing n pairs of parentheses which are correctly matched.
For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children)
with n+1 leaves.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;

	int *dp = new int[n+1];
	for(int i=0;i<n+1;i++) dp[i] = 0;

	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++)
			dp[i] += dp[j-1] * dp[i-j];
	}

	for(int i=1;i<=n;i++)
		cout<<dp[i]<<" ";

	return 0;
}