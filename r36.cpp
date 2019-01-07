// Array Partition Problem (Recursive Approach)
// Program to Find Whether the Array Partition is Possible in Two Equal Sums or Not
// https://www.geeksforgeeks.org/partition-problem-dp-18/

#include<bits/stdc++.h>
using namespace std;

bool cal(int *a, int n, int sum){

	if(sum==0) return true;
	if(sum!=0 and n==0) return false;
	return (a[n-1]+cal(a,n-1,sum-a[n-1]) || cal(a,n-1,sum));
}

int main(){
	
	int a[]={1,5,3,3};
	int n=sizeof(a)/sizeof(int);
	int sum=0;
	for(auto i:a)
		sum+=i;

	if(sum&1){
		cout<<"No";
		return 0;
	}
	else{
		if(cal(a,n,sum/2)==1) cout<<"Yes";
		else cout<<"No";
	}

	return 0;
}