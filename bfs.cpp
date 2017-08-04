#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// function returns noofvertices in a graph
// this graph has vertices value ranging from 0 - n-1 and is undirected 

int bfs(vector<vector<int > > G){
	int n = G.size();
	int count = 0;
	vector<bool > visited(n,false);
	queue<int > q;
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int index = q.front();
		q.pop();
		int m = G[index].size();
		for(int i = 0; i < m; i++){
			if(!visited[G[index][i]]){
				q.push(G[index][i]);
				count++;
				visited[G[index][i]] = true;
			}
		}
	}

	return count;
}
//graph inputs
//6 3 1 2 3 2 0 3 4 0 3 5 4 4 1 0 2 5 2 2 5 3 2 4 3

int main(int argc, char const *argv[])
{
	vector<vector<int > > G;
	int n;
	cin>>n; // no. of vertices in graph
	G.resize(n);
	for(int i = 0; i < n; i++){
		int m;
		cin>>m;
		for(int j = 0; j < m; j++){
			int temp;
			cin>>temp;
			G[i].push_back(temp);
		}
	}
	int count = bfs(G);
	cout<<count;
	return 0;
}