// REPOSTS CODEFORCES
// DP on TREES
// http://codeforces.com/contest/522/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MAX 501

vector <int> AdjList[MAX];
unordered_map<string,int> dp;

int dfs(int u){

	int mx=0;

	for(auto child:AdjList[u]){
		mx=max(mx,1+dfs(child));
	}
	return mx;
}

string toLower(string str){
	
	transform(str.begin(),str.end(),str.begin(),::tolower);
	return str;
}

int main(){

	int test;
	cin>>test;

	unordered_map<string,int> Map;
	
	while(test--){
		
		string a,b,c;
		cin>>a>>b>>c;

		a=toLower(a);
		c=toLower(c);
		
		if(Map.count(a)==0) Map[a]=Map.size()+1;
		if(Map.count(b)==0) Map[b]=Map.size()+1;
		
		AdjList[Map[c]].push_back(Map[a]);
	}

	cout<<1+dfs(Map["polycarp"]);

	return 0;
}