#include <iostream>
using namespace std;

void dfs1(int u, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& st){
	vis[u] = true;		
	for(int v: adj[u]){
		if(vis[v]) continue;
		dfs1(v, vis, adj, st);
		st.push(v);
	}
}

void dfs2(int u, vector<bool>& vis, vector<vector<int>>& rev, vector<int>& component){
	vis[u] = true;
	component.push_back(u);
	for(int v: rev[u]){
		if(vis[v]) continue;
		dfs2(v, vis, rev, component);	
	}
}

// finds all the strongly connected components in a DAG
vector<vector<int>> kosaraju(vector<vector<int>> adj){
	int n = adj.size();
	vector<bool> vis(n);
	stack<int> st;
	for(int i = 0; i < n; i++){
		if(not vis[i]) dfs1(i, vis, adj, st);
	}
	
	vector<vector<int>> rev(n, vector<int>());
	for(int u = 0; u < n; u++){
		for(int v: adj[u]) rev[v].push_back(u);
	}
	
	vector<vector<int>> components;
	fill(vis.begin(), vis.end(), false);	
	while(not st.empty()){
		int u = st.top(); st.pop();
		if(not vis[u]){
			vector<int> c; 
			dfs2(u, vis, rev, c);
			components.push_back(c);
		}
	}

	return components;
}

int main() {
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int u, v; 
		cin >> u >> v;
		adj[u].push_back(v);
	}	
	vector<vector<int>> components = kosaraju(adj);
	for(auto c: components){
		for(int x: c){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
