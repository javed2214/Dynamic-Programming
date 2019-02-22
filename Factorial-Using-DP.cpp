// Program to Find Factorial of Any Number using Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	long long fact[n+1];
	fact[0]=1;
	for(int i=1;i<=n;i++)
		fact[i]=i*fact[i-1];

	cout<<fact[n];

	return 0;
}