#include <iostream>
using namespace std;

#define pii pair<int,int>

vector<pii> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void bfs(vector<vector<int>>&heights, vector<vector<bool>> &vis, int r, int c, int m, int n){
	vis[r][c] = true;	
	queue<pii> q;
	q.push({r,c});
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		for(pii d: dir){
			int nr = cur.first + d.first;
			int nc = cur.second + d.second;
			if(nr >= m or nr < 0 or nc >= n or nc < 0) continue;
			if(heights[nr][nc] < heights[cur.first][cur.second]) continue;
			if(vis[nr][nc]) continue;
			q.push({nr, nc});
			vis[nr][nc] = true;
		}
	}
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
	int m = heights.size();
	int n = heights[0].size();
	vector<vector<bool>> atlantic(m, vector<bool>(n));
	vector<vector<bool>> pacific(m, vector<bool>(n));
	for(int i = 0; i<m; i++){
		bfs(heights, pacific, i, 0, m, n);
		bfs(heights, atlantic, i, n-1, m, n);
	}
	for(int j = 0; j<n; j++){
		bfs(heights, pacific, 0, j, m, n);
		bfs(heights, atlantic, m-1, j, m, n);
	}
	vector<vector<int>> result;
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			if(pacific[i][j] and atlantic[i][j]) result.push_back({i, j});
		}
	}
	return result;
}

int main() {
	int M, N; cin >> M >> N;
	vector<vector<int>> v(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	for(auto &a: pacificAtlantic(v)){
		cout << a[0] << " " << a[1] << endl;
	}
	return 0;
}
