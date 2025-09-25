#include <iostream>
using namespace std;

vector<int> bellman_ford(int n, int src, vector<vector<int>> edges){
	vector<int> d(n, INT_MAX);
	d[src] = 0;
	for(int i = 0; i < n - 1; i++){
		for(auto e: edges){
			int u = e[0], v = e[1], w = e[2];
			if(d[u] == INT_MAX) continue;
			d[v] = min(d[v], d[u] + w);
		}
	}
	// run a nth pass for cycle detection
	return d;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges;
	for(int i = 0; i < m; i++){
		int u, v, w; cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	int src; cin >> src;
	vector<int> res = bellman_ford(n, src, edges);
	for(int x: res){
		cout << x << " ";
	}
	return 0;
}
