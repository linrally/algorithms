#include <iostream>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
	int n = text1.size();
	int m = text2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // dp[i][j] is LCS of A[1...i] and B[1...j]
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 or j == 0){
				dp[i][j] = 0;
				continue;
			}
			if(text1[i - 1] == text2[j - 1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int main() {
	string s, t; cin >> s >> t;
	cout << longestCommonSubsequence(s, t) << endl;
	return 0;
}
