// Subset Sum Problem
// To Check Whether the Given Sum can be Obtained
// From the All possible Combination of Array Elements

#include<bits/stdc++.h>
using namespace std;

bool SubsetSum(int *a, int n, int sum){
	if(sum==0)
		return true;
	if(n==0 and sum!=0)
		return false;
	if(sum<a[n-1])
		return SubsetSum(a,n-1,sum);
	else
		return (SubsetSum(a,n-1,sum-a[n-1]) || SubsetSum(a,n-1,sum));
}

int main(){
	int n,a[]={12,7,8,23,9,10};
	n=sizeof(a)/sizeof(int);
	int sum=50	;
	bool x=SubsetSum(a,n,sum);
	if(x==true) cout<<"Found a Subset with Given Sum";
	else cout<<"Not Found";

	return 0;
}