// Count Subarrays (Codechef)
// https://www.codechef.com/problems/SUBINC

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int test;
	cin>>test;

	while(test--){

		ll n,c=0,res=0;
		cin>>n;
		ll a[n];
		for(int i=0;i<n;i++) cin>>a[i];

		for(int i=1;i<n;i++){
			if(a[i] >= a[i-1]){
				c++;
				res+=c;
			}
			else c=0;
		}
		cout<<res+n<<"\n";
	}
	return 0;
}