#include <iostream>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		long long sum = 0;
		long long negSum = 0;
		int minAbs = INT_MAX;
		int negCount = 0;
		int zeroCount = 0;
		for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
						sum += matrix[i][j];
						minAbs = min(minAbs, abs(matrix[i][j]));
						if(matrix[i][j] < 0) {
								negSum += abs(matrix[i][j]);
								negCount++;
						} else if (matrix[i][j] == 0){
								zeroCount++;
						}
				}
		}
		if(negCount % 2 == 0 or zeroCount > 0){
				return sum + 2 * negSum;
		} else {
				return sum + 2 * negSum - 2 * minAbs;
		}
}

int main() {
	int N; cin >> N;
	vector<vector<int>> v(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	cout << maxMatrixSum(v) << endl;
	return 0;
}
