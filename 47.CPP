// Recursive Program to Print All Possible Subsequences

#include<bits/stdc++.h>
using namespace std;

void Subsequence(string s1, string s2, int i){
	int n=s1.length();
	if(i==n){
		cout<<"{"<<s2<<"}  ";
		return;
	}
	Subsequence(s1,s2,i+1);
	Subsequence(s1,s2+s1[i],i+1);
}

int main(){
	string s1,s2;
	int i=0;
	cin>>s1;
	Subsequence(s1,s2,i);

	return 0;
}