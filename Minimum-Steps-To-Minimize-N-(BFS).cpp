// Minimum Steps to inimize N Using BFS

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001

int bfs(int n){

	vector <int> dis(MAX, -1);
	queue <int> q;
	q.push(n);
	dis[n] = 0;

	while(!q.empty()){

		int temp = q.front();
		q.pop();

		if(temp == 1) return dis[temp];

		if(temp - 1 > 0 and dis[temp - 1] == -1){
			dis[temp - 1] = 1 + dis[temp];
			q.push(temp - 1);
		}
		if(temp % 2 == 0 and dis[temp / 2] == -1){
			dis[temp / 2] = 1 + dis[temp];
			q.push(temp / 2);
		} 
		if(temp % 3 == 0 and dis[temp / 3] == -1){
			dis[temp / 3] = 1 + dis[temp];
			q.push(temp / 3);
		}
	}
	return -1;
}

int main(){

	int n;
	cin>>n;

	cout << bfs(n);

	return 0;
}