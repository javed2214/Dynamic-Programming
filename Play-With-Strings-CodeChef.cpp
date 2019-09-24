// Play With Strings (CodeChef)
// https://www.codechef.com/COCR2015/problems/COCR02
// You will be given a string S with lower-case alphabets only.
// You have to count the number of substrings which start and end at the same character and has an odd length.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ll t;
	cin>>t;

	while(t--){

		string s;
		cin>>s;

		ll cnt = 0;

		for(int i=0;i<26;i++){
			int px[2] = {0,0};
			for(int j=0;j<s.length();j++){
				if(s[j] == (i + 'a')){
					px [j % 2]++;
					cnt += px [j % 2];
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}