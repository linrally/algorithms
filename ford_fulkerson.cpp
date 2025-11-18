#include <iostream>
using namespace std;

struct Edge{ // directed u -> v with cap c
	int u {};
	int v {};
	int c {};
};

int maxflow(const int n, const vector<Edge>& edges, const int s, const int t){
	vector<vector<int>> cap(n, vector<int>(n)); // stores residual capacity from u to v

	for(Edge e: edges){
		cap[e.u][e.v] += e.c; // += because if there are multiple edges, we merge them
	}

	int flow = 0;

	while(true){
		// find an augmenting path
		vector<int> par(n, -1); // doubles as vis array
		queue<int> q;
		par[s] = s;
		q.push(s);
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(int v = 0; v < n; v++){
				if(par[v] != -1) continue;
				// forward edge residual
				if(cap[cur][v] > 0){
					q.push(v);
					par[v] = cur;
				}
			}
		}

		if(par[t] == -1) break;
		
		// reconstruct the path and find the bottleneck capacity
		int bottleneck = INT_MAX;
		for (int v = t; v != s; v = par[v]) {
			int u = par[v];
			bottleneck = min(bottleneck, cap[u][v]);
		}

		for (int v = t; v != s; v = par[v]) {
			int u = par[v];
			cap[u][v] -= bottleneck;
			cap[v][u] += bottleneck;
		}

		flow += bottleneck;
	}

	return flow;
}

int main() {
	int N; cin >> N;
	int M; cin >> M;
	vector<Edge> edges(M);
	for(int i = 0; i < M; i++){
	    cin >> edges[i].u >> edges[i].v >> edges[i].c;
	}
	int s, t; cin >> s >> t;
	cout << maxflow(N, edges, s, t) << endl;
	return 0;
}
