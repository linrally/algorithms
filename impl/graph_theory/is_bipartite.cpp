#include <iostream>
using namespace std;

// bipartite: nodes can be partitioned into two groups L and R s/t there are connections from L/R or R/L but not R/R or L/L
// proof: G is bipartite iff all cycles are event length
bool is_bipartite(vector<vector<int>> adj){
	int n = adj.size();
	vector<int> dist(n, -1);
	queue<int> q;

	for(int i = 0; i < n; i++){
		if (dist[i] != -1) continue;
		q.push(i); 
		dist[i] = 0;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int v: adj[cur]){
				if(dist[v] == dist[cur]){
					return false;
				} else if(dist[v] == -1){
					dist[v] = dist[cur] + 1;
					q.push(v);
				}
			}
		}
	}
	return true;
}

int main(){
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << is_bipartite(adj) << endl;
	return 0;
}

