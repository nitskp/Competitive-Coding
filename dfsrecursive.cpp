#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > G, int s, vector<bool > &visited){
		visited[s] = true;
		cout<<s<<" -> ";
		for(int i = 0; i < G[s].size(); i++){
			if(!visited[G[s][i]]){
				dfs(G,G[s][i],visited);	
			}
		}
}

//input would be given by providing no. of edges and vertex
/*
12
13
0 3
0 2
0 1
3 8
2 9
9 10
9 11
2 4
4 9
1 7
1 5
7 6
6 5
*/

int main(int argc, char const *argv[])
{
	vector<vector<int > > G;
	int m, n; // m = no. of  vertices and n = no. of vertices
	cin>>m>>n;
	G.resize(m);
	vector<bool> visited(m,false);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	dfs(G,0,visited);
	return 0;
}