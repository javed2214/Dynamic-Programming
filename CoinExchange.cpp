// Coin Exchange Problem
/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of 
S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}.
There are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include<bits/stdc++.h>
using namespace std;

int coinExchange(int *a, int n, int c){
	if(c==0)
		return 1;
	if(c<0)
		return 0;
	if(c>=0 and n<=0)
		return 0;
	return (coinExchange(a,n-1,c) + coinExchange(a,n,c-a[n-1]));
}

int main(){
	int a[]={1,2,3};
	int n=sizeof(a)/sizeof(int);
	int c=4;
	cout<<coinExchange(a,n,c);

	return 0;
}
