#include <iostream>
#include <unordered_set>

using namespace std;

static bool hasViolation(const vector<vector<char>>& board, int lastRow, int lastCol){
	int M = board.size();
	int N = board[0].size();
	bool seen[10] = {};
	for(int i = 0; i < N; i++){
		if(board[lastRow][i] == '.') continue;
		int d = board[lastRow][i] - '0';
		if(seen[d]) return true;
		seen[d] = true;
	}
	memset(seen, 0, sizeof(seen));
	for(int i = 0; i < M; i++){
		if(board[i][lastCol] == '.') continue;
		int d = board[i][lastCol] - '0';
		if(seen[d]) return true;
		seen[d] = true;
	}
	memset(seen, 0, sizeof(seen));
	int iq = lastRow/3;
	int jq = lastCol/3;
	for(int i = 3 * iq; i < 3 * iq + 3; i++){
		for(int j = 3 * jq; j < 3 * jq + 3; j++){
			if(board[i][j] == '.') continue;
			int d = board[i][j] - '0';
			if(seen[d]) return true;
			seen[d] = true;
		}
	}
	return false;
}


static void printBoard(vector<vector<char>>& board){
	for(auto& row: board){
		for(auto& ele: row){
			cout << ele << " ";
		}
		cout << endl;
	}
}

bool dfs(vector<vector<char>>& board){
	int M = board.size();
	int N = board[0].size();
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(board[i][j] == '.'){
				for(int k = 1; k <= 9; k++){
					board[i][j] = '0' + k;
					if(not hasViolation(board, i, j)){
						if(dfs(board)) return true;
					}
					board[i][j] = '.';
				}
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(vector<vector<char>>& board) {
		dfs(board);	
}

int main() {
	int M, N; cin >> M >> N;
	vector<vector<char>> v(M, vector<char>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	solveSudoku(v);
	printBoard(v);
	return 0;
}
