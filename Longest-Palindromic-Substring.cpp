// Longest Palindromic Substring
// Classical Dynamic Programming Probelm

// https://www.youtube.com/watch?v=UflHuQj6MVA		 *** Best Tutorial ***

// geeksforgeeks.org/longest-palindrome-substring-set-1/
// https://leetcode.com/problems/longest-palindromic-substring/

#include<bits/stdc++.h>
using namespace std;

string printSubstring(string s, int start, int end){

	string str;

	for(int i=start;i<=end;i++)
		str += s[i];

	return str;
}

int LPS(string s){

	int n = s.length();

	int dp[n][n];
	
	memset(dp, 0, sizeof(dp));

	for(int i=0;i<n;i++) dp[i][i] = 1;

	int start = 0, maxLength = 1;

	for(int i=0;i<n-1;i++){
		
		if(s[i] == s[i+1]){
		
			dp[i][i+1] = 1;
			maxLength = 2;
			start = i;
		}
	}

	for(int k=3;k<=n;++k){
		
		for(int i=0;i<n-k+1;++i){

			int j = i + k - 1;

			if(dp[i+1][j-1] == 1 and s[i] == s[j]){

				dp[i][j] = 1;

				if(k > maxLength){

					start = i;
					maxLength = k;
				}
			}
		}
	}
	cout << "Longest Palindromic Substring is: " << printSubstring(s, start, start + maxLength - 1) << endl;

	return maxLength;
}

int main(){

	string s;
	cin>>s;

	cout << "Length : " << LPS(s);

	return 0;
}