// https://www.codechef.com/problems/SUMTRIAN

#include<bits/stdc++.h>
using namespace std;

int Compute(int a[105][105], int n, int row, int col, int dp[105][105]){
    if(row==n){
        dp[row][col]=a[row][col];
        return dp[row][col];
    }
    if(dp[row][col]!=-1)
        return dp[row][col];

    return dp[row][col]=max(a[row][col]+Compute(a,n,row+1,col,dp), a[row][col]+Compute(a,n,row+1,col+1,dp));
}

int main(){
    int n,test;
    cin>>test;
    while(test--){
        cin>>n;
        int a[105][105];
        int k=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                cin>>a[i][j];
            }
            ++k;
        }
        int dp[105][105];
        memset(dp,-1,sizeof(dp));

        cout<<Compute(a,n-1,0,0,dp)<<endl;
    }

    return 0;
}