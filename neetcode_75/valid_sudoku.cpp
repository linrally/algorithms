#include <iostream>
#include <unordered_set>
#include <cctype>
using namespace std;

bool validArray(vector<int> v){
	unordered_set<int> s;
	for(int x:v){
		if(s.contains(x)) return false;
		s.insert(x);
	}
	return true;
}

// optimal: bitmasking
bool isValidSudoku(vector<vector<char>>& board){
	for(int i = 0; i<9; i++){
		vector<int> col;
		vector<int> row;
		for(int j = 0; j<9; j++){
			if(isdigit(board[i][j])) col.push_back(board[i][j] - '0');		
			if(isdigit(board[j][i])) row.push_back(board[j][i] - '0');
		}
		if(not validArray(col) or not validArray(row)) return false;
	}
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			vector<int> grid;
			for(int k = 3*i; k < 3*i + 3; k++){
				for(int l = 3*j; l < 3*j + 3; l++){
					if(isdigit(board[k][l])) grid.push_back(board[k][l] - '0');	
				}
			}
			if(not validArray(grid)) return false;
		}
	}
	return true;
}

int main() {
	int M, N; cin >> M >> N;
	vector<vector<char>> v(M, vector<char>(N));
	for (int i = 0; i < M; i++) {
		string row; cin >> row;
		for (int j = 0; j < N; j++) {
			v[i][j] = row[j];
		}
	}
	cout << isValidSudoku(v) << endl;
	return 0;
}
