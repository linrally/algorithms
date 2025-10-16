#include <iostream>
#include <unordered_set>
using namespace std;

// use union find, but bfs/dfs works as well
// no rank optimization

int find(int u, vector<int> &parent){
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u], parent); // path compression
}

bool f_union(int u, int v, vector<int> &parent){
	int pu = find(u, parent); 
	int pv = find(v, parent);
	if(pu == pv) return false;
	parent[pv] = pu;	
	return true;
}

int countComponents(int n, vector<vector<int>>& edges) {
	vector<int> parent(n);	
	for(int i = 0; i<n; i++){
		parent[i] = i;
	}
	for(auto &e: edges){
		f_union(e[0], e[1], parent);
	}
	unordered_set<int> st;
	for(int i = 0; i<n; i++){
		st.insert(find(i, parent));
	}
	return st.size();
}

int main() {
	int N; cin >> N;
	int M; cin >> M;
	vector<vector<int>> v(M, vector<int>(2));
	for(int i = 0; i < M; i++){
	    cin >> v[i][0] >> v[i][1];
	}
	cout << countComponents(N, v) << endl;
	return 0;
}
