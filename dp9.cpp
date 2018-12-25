// Staircase Problem (Recursive Approach)

#include<bits/stdc++.h>
using namespace std;

int Ladder(int n, int k){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	int ans=0;
	for(int i=1;i<=k;i++)
		ans+=Ladder(n-i, k);
	return ans;
}

int main(){
	int n=4; 		// No of Staircase
	int k=2; 		// Max no of Steps can be taken
	cout<<Ladder(n,k);

	return 0;
}

// OUTPUT ==>> 5
/*
1 1 2
2 2
2 1 1
1 2 1
1 1 1 1
*/