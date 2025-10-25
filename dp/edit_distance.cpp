#include <iostream>
using namespace std;

// hor_
// hors 
// dp[i][j] = dp[i][j-1] + 1;

// hors
// hor_ 
// dp[i][j] = dp[i-1][j] + 1;

// hors
// hork 
// dp[i][j] = dp[i-1][j-1] + 1;

int minDistance(string word1, string word2) {
	int n = word1.size();
	int m = word2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1)); // minimum ops to convert A[1...i] to B[1...j]
	for (int i = 0; i <= n; i++) dp[i][0] = i;
	for (int j = 0; j <= m; j++) dp[0][j] = j;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(word1[i - 1] == word2[j - 1]){ // if ith and jth characters are equal, no additional cost incurred
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
			}
		}
	}

	return dp[n][m];
}

int main() {
	string s, t; cin >> s >> t;
	cout << minDistance(s, t) << endl;
	return 0;
}
