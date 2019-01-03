// Staircase Problem (Recursive Approach)

#include<bits/stdc++.h>
using namespace std;

int Ladder(int n){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	else
		return (Ladder(n-1)+Ladder(n-2)+Ladder(n-3));  // Since k=3
}

int main(){
	int n=7; 		// No of Staircase
	int k=3; 		// Max no of Steps can be taken
	cout<<Ladder(n);

	return 0;
}
