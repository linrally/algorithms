#include <iostream>
using namespace std;

vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &vis){
	vis[r][c] = true;
	int m = grid.size();
	int n = grid[0].size();
	for(auto p: directions){
		int nr = r + p.first;
		int nc = c + p.second;
		if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
		if(grid[nr][nc] == '0' or vis[nr][nc]) continue;
		dfs(nr, nc, grid, vis);
	}
}

int numIslands(vector<vector<char>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>> vis(m, vector<bool>(n));
	int count = 0;
	for(int i = 0; i<m; i++){
		for(int j = 0; j<n; j++){
			if(not vis[i][j] and grid[i][j] == '1'){
				dfs(i, j, grid, vis);
				count++;
			}
		}
	}
	return count;
}

int main() {
	int M, N; cin >> M >> N;
	vector<vector<char>> v(M, vector<char>(N));
	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			v[i][j] = s[j];
		}
	}
	cout << numIslands(v) << endl;
	return 0;
}
