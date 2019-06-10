// Maximum Sum from Root to Leaves
// DP on TREES
// https://www.geeksforgeeks.org/dynamic-programming-trees-set-1/
// https://www.youtube.com/watch?v=gm4Ye0fESpU&list=PLfBJlB6T2eOsET4tlfcLs7oXR7kCyt1xc

#include<bits/stdc++.h>
using namespace std;
#define MAX 101

vector<int> AdjList[MAX];
int a[MAX],dp[MAX];

void dfs(int u, int par){

	dp[u]=a[u];
	int mx=0;

	for(auto child:AdjList[u]){
		if(child==par) continue;
		dfs(child,u);
		mx=max(mx,dp[child]);
	}
	dp[u]+=mx;
}

int main(){

	int n;
	cin>>n;

	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}
	for(int i=1;i<=n;i++) cin>>a[i];

	dfs(1,0);
	
	cout<<dp[1];

	return 0;
}