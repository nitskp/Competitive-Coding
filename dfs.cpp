// iterative approach for dfs
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int > > G, int q){
	int n = G.size();
	bool visited[n] = {false};
	stack<int> s;
	s.push(q);
	visited[q] = true;
	while(!s.empty()) {
	    int temp = s.top();
	    s.pop();
	    cout<<temp<<" -> ";
	    for(int i = 0; i < G[temp].size(); i++){
	    	if(visited[G[temp][i]] == false)	
	    	{
	    		visited[G[temp][i]] = true;
	    		s.push(G[temp][i]);
	    }
	}
}

}

//input would be given by providing no. of edges and vertex
/*
13
13
0 3
0 2
0 1
3 8
2 9
9 10
9 11
2 12
12 9
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
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	dfs(G,0);
	return 0;
}