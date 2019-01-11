// Minimum Jumps Required to Reach the End of an Array
// https://leetcode.com/problems/jump-game-ii/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define FASTREAD ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define SIZE 10000000

int main(){

	int a[]={2,1,3,2,3,4,5,1,2,8};
	int n=sizeof(a)/sizeof(int);

	int minJump[n];
	minJump[0]=0;
	for(int i=1;i<n;i++)
		minJump[i]=INT_MAX;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]+j>=i)
				minJump[i]=min(minJump[i],minJump[j]+1);
		}
	}
	cout<<minJump[n-1];

	return 0;
}