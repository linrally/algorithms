#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

double dfs(unordered_map<string, vector<pair<string, double>>> &adj, string target, string cur, unordered_set<string> &vis){
	if(cur == target) return 1.0; 
	for(auto& p: adj[cur]){
		string u = p.first;
		double v = p.second;	
		if(vis.contains(u)) continue;
		vis.insert(u);
		double path = dfs(adj, target, u, vis);
		if(path == -1.0) continue;
		return path * v;
	}
	return -1.0;
}


vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	int n = equations.size();
	unordered_map<string, vector<pair<string, double>>> adj;	
	for(int i = 0; i < n; i++){
		string x = equations[i][0];
		string y = equations[i][1];
		double value = values[i];
		adj[x].push_back({y, value});
		adj[y].push_back({x, 1.0 / value});
	}
	int m = queries.size();
	vector<double> ans(m);
	for(int i = 0; i < m; i++){
		string x = queries[i][0];
		string y = queries[i][1];
        if((not adj.contains(x)) or (not adj.contains(y))){
            ans[i] = -1.0;
            continue;
        }
		unordered_set<string> vis;
		ans[i] = dfs(adj, y, x, vis);
	}
	return ans;
}

int main() {
	return 0;
}
