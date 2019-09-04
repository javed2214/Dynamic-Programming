// Maximum Length Chain of Pairs
// https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/

#include<bits/stdc++.h>
using namespace std;

int maxLength(pair <int,int> *P, int n){

	sort(P,P+n);

	int mcl[n];
	
	for(int i=0;i<n;i++) mcl[i] = 1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(P[i].first > P[j].second and mcl[i] < mcl[j] + 1)
				mcl[i] = mcl[j] + 1;
		}
	}

	return *max_element(mcl, mcl + n);
}

int main(){

	pair <int,int> P[4];

	P[0] = {5,24};
	P[1] = {15,25};
	P[2] = {27,40};
	P[3] = {50,60};

	int n = 4;

	cout<<maxLength(P,n);

	return 0;
}