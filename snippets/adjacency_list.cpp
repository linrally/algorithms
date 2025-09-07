#include <iostream>
using namespace std;

int main(){
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		// undirected
		adj[u].push_back(v); 
		adj[v].push_back(u);
	}
	return 0;
}

