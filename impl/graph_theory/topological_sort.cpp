#include <iostream>
using namespace std;

vector<int> topological_sort(vector<vector<int>> adj){
	int n = adj.size();
	vector<int> res;
	vector<int> indeg(n);
	for(int u = 0; u<n; u++){
		for(int v: adj[u]){
			indeg[v]++;
		}
	}
	queue<int> q;
	for(int i = 0; i<n; i++){
		if(indeg[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int cur = q.front(); q.pop();
		res.push_back(cur);
		for(int u:adj[cur]){
			indeg[u]--;
			if(indeg[u] == 0) q.push(u);
		}
	}
	return res;
}

int main(){
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v); 
	}
	vector<int> res = topological_sort(adj);
	if(res.size() == 0) cout << -1 << endl;
	for(int x: res){
		cout << x << " ";
	}
	return 0;
}

