// To Find nth Fibbonacci Number using Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

int fib(int *a, int n){
	if(n<=1)
		return n;
	if(a[n]!=-1)
		return a[n];
	a[n]=fib(a,n-1)+fib(a,n-2);
	
	return a[n];
}
int main(){

	int n;
	int a[101];
	cin>>n;
	for(int i=0;i<101;i++)
		a[i]=-1;
	cout<<fib(a,n);

	return 0;
}
