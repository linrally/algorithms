#include <iostream>
using namespace std;

void bfs(vector<vector<int>> adj, vector<bool> &vis, int src){
	queue<int> q;
	vis[src] = true;
	q.push(src);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(int v: adj[cur]){
			if (!vis[v]){
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

// counts the number of connected components in an undirected graph
int conn_components(vector<vector<int>> adj){
	int n = adj.size();
	int count = 0;
	vector<bool> vis(n);
	for(int i = 0; i<n; i++){
		if(!vis[i]){
			count++;
			bfs(adj, vis, i);
		}
	}
	return count;
}

int main(){
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << conn_components(adj) << endl;
	return 0;
}

