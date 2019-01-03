// Program to Find Length of Longest Common Subsequence using Recursion

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int l1, int l2){
	if(l1==0 || l2==0)
		return 0;
	if(s1[l1-1]==s2[l2-1])
		return 1+LCS(s1,s2,l1-1,l2-1);
	else
		return max(LCS(s1,s2,l1-1,l2), LCS(s1,s2,l1,l2-1));
}

int main(){
	string str1, str2;
	cin>>str1>>str2;
	int l1=str1.length();
	int l2=str2.length();
	
	cout<<LCS(str1,str2,l1,l2);

	return 0;
}
