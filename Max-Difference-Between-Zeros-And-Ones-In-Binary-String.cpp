// Maximum Difference Between Zeros and Ones in a Binary String

// Given a binary string of 0s and 1s. The task is to find the maximum difference
// between the number of 0s and number of 1s in any sub-string of the given binary string.
// That is maximize ( number of 0s – number of 1s ) for any sub-string in the given binary string.

// In the post we seen an efficient method that work in O(n) time and in O(1) extra space.
// Idea behind that if we convert all zeros into 1 and all ones into -1.
// now our problem reduces to find out the maximum sum sub_array Using Kadane’s Algorithm.

#include<bits/stdc++.h>
using namespace std;

int main(){

	string str = "11000010001";
	int n = str.length();

	int sum = 0, mx = 0;

	for(int i=0;i<n;i++){

		sum += (str[i] == '0') ? 1 : -1;
		mx = max(mx, sum);
		if(sum < 0) sum = 0;
	}

	cout<<mx;

	return 0;
}