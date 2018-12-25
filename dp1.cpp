// 0/1 Knapsack Problem using Recursion

#include<bits/stdc++.h>
using namespace std;

int knapsack(int *val, int *wt, int cap, int n){
	if(n==0 || cap==0)
		return 0;

	if(wt[n-1]>cap)
		return knapsack(val,wt,cap,n-1);
	
	else
		return max(knapsack(val,wt,cap,n-1), val[n-1]+knapsack(val,wt,cap-wt[n-1],n-1));
}

int main(){

	int val[]={20,40,70,30,60};
	int wt[]={1,2,3,4,5};
	int n=sizeof(wt)/sizeof(int);
	int cap=4;
	cout<<knapsack(val,wt,cap,n);

	return 0;
}