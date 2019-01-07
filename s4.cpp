// LCS With Permutations Allowed

#include<bits/stdc++.h>
using namespace std;

void lcsPermu(string s1, string s2){

	int count1[26], count2[26];
	memset(count1,0,sizeof(count1));
	memset(count2,0,sizeof(count2));

	for(int i=0;i<s1.length();i++)
		count1[s1[i]-'a']++;

	for(int i=0;i<s2.length();i++)
		count2[s2[i]-'a']++;

	string res;

	for(int i=0;i<26;i++){
		for(int j=1;j<=min(count1[i],count2[i]);j++)
			res.push_back(i+'a');
	}
	cout<<res;
}

int main(){

	string s1="cake";
	string s2="geek";
	
	lcsPermu(s1,s2);

	return 0;
}