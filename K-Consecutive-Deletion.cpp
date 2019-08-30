// K Consecutive Deletion
// Program to Find Largest Sum after Deleting K Consecutive Elements
// https://www.codechef.com/problems/CYAUG02

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int n,k;
	cin>>n>>k;

	int a[n];
	ll total = 0, sum = 0;

	for(int i=0;i<n;i++){

		cin>>a[i];
		total += a[i];
	}

	for(int i=0;i<k;i++) sum += a[i];

	ll res = LONG_MIN;

	res = max(res, total - sum);

	for(int i=k;i<n;i++){

		sum += a[i];
		sum -= a[i-k];
		res = max(res, total - sum);
	}

	cout<<res<<endl;

	return 0;
}