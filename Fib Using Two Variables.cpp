// Program to Print Fibonacci Series by Using Two Variables

#include<bits/stdc++.h>
using namespace std;

void fib(int n){
	int a=0,b=1;
	if(n>=0)
		cout<<a<<" ";
	if(n>=1)
		cout<<b<<" ";
	for(int i=2;i<=n;i++){
		cout<<a+b<<" ";
		b=a+b;
		a=b-a;
	}
}

int main(){
	int n=9;
	fib(n);

	return 0;
}
