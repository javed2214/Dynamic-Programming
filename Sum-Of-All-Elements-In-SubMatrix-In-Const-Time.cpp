// Program to Find Sum of All the Elements in a SubMatrix in a Constant Time
// https://www.techiedelight.com/calculate-sum-elements-sub-matrix-constant-time/

#include<bits/stdc++.h>
using namespace std;
#define M 5
#define N 5

int findSubmatrixSum(int mat[M][N], int p, int q, int r, int s){

	int sum[M][N];

	sum[0][0] = mat[0][0];

	for(int i=1;i<M;i++) sum[i][0] = mat[i][0] + sum[i-1][0];
	for(int i=1;i<N;i++) sum[0][i] = mat[0][i] + sum[0][i-1];

	for(int i=1;i<M;i++)
		for(int j=1;j<N;j++)
			sum[i][j] = mat[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

	int total = sum[r][s];

	// total = sum[r][s] - sum[r][q-1] - sum[p-1][s] + sum[p-1][q-1]

	if(q - 1 >= 0) total -= sum[r][q - 1];
	if(p - 1 >= 0) total -= sum[p - 1][s];
	if(p - 1 >= 0 and q - 1 >= 0) total += sum[p - 1][q - 1];

	return total;
}

int main(){

	int mat[M][N] = {
		{ 0, 2, 5, 4, 1 },
		{ 4, 8, 2, 3, 7 },
		{ 6, 3, 4, 6, 2 },
		{ 7, 3, 1, 8, 3 },
		{ 1, 5, 7, 9, 4 }
	};

	// (p, q) and (r, s) represents top-left and bottom-right
	// coordinates of the sub-matrix
	int p = 1, q = 1, r = 3, s = 3;

	cout << findSubmatrixSum(mat, p, q, r, s);

	return 0;
}