// Playing With Numbers - CodeChef
// https://www.codechef.com/problems/PLYNUM

#include<bits/stdc++.h>
using namespace std;
#define MAX 2001

int bfs(int a, int b){

	vector <int> dis(MAX, -1);
	queue <int> q;
	q.push(a);
	dis[a] = 0;

	while(!q.empty()){

		int temp = q.front();
		q.pop();

		if(temp == b) return dis[temp];

		if(temp - 1 >= 0 and dis[temp - 1] == -1){
			dis[temp - 1] = 1 + dis[temp];
			q.push(temp - 1);
		}
		if(temp + 3 < MAX and dis[temp + 3] == -1){
			dis[temp + 3] = 1 + dis[temp];
			q.push(temp + 3);
		}
		if(temp * 2 < MAX and dis[temp * 2] == -1){
			dis[temp * 2] = 1 + dis[temp];
			q.push(temp * 2);
		}
	}
	return -1;
}

int main(){

	int t;
	cin>>t;

	while(t--){

		int a,b;
		cin >> a >> b;

		cout << bfs(a,b) << endl;
	}

	return 0;
}