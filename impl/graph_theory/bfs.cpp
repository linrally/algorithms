#include <iostream>
using namespace std;

// returns the shortest path from src to dest
// one of many applications of bfs
int bfs(vector<vector<int>> adj, int src, int dest){ 
	vector<int> dist(adj.size(), -1);

	queue<int> q;
	q.push(src);
	dist[src] = 0;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int v: adj[cur]){
			if(dist[v] == -1){
				q.push(v);
				dist[v] = dist[cur] + 1;
			}
		}
	}

	return dist[dest];
}

int main(){
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int src, dest; cin >> src >> dest;
	cout << bfs(adj, src, dest) << endl;
	return 0;
}
