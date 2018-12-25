// Program to Find Max Sum such that No Two Elements are Adjacent to Each Other using Recursion

#include<bits/stdc++.h>
using namespace std;

int findMax(int *a, int n){
	if(n<=0)
		return 0;
	return max(a[n-1]+findMax(a,n-2), findMax(a,n-1));
}

int main(){
	int a[]={9,3,1,6,8,9,7,4};
	int n=sizeof(a)/sizeof(int);
	cout<<findMax(a,n);

	return 0;
}
// OUTPUT ====>> 28