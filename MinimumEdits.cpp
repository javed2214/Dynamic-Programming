// Given two strings str1 and str2 and below operations that can performed on str1.
// Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
// Insert
// Remove
// Replace
// All of the above operations are of equal cost. (Recursion)

#include<bits/stdc++.h>
using namespace std;

int editString(string str1,string str2,int m,int n){
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(str1[m-1]==str2[n-1])
		return editString(str1,str2,m-1,n-1);
	return 1+min(
					editString(str1,str2,m,n-1),		// Insert
					min(editString(str1,str2,m-1,n),	// Delete
					editString(str1,str2,m-1,n-1))		// Replace
				);
}
int main(){
	string str1="sunday";
	string str2="saturday";
	int m=str1.length();
	int n=str2.length();

	cout<<editString(str1,str2,m,n);

	return 0;
}
