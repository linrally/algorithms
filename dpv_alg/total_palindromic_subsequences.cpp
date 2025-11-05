#include <iostream>
using namespace std;

/*
 * Find the total number of (not necessarily distinct) palindromic subsequences in a string
 * As long as the two substrings' corresponding indices are not identical, add both to the solution set (uniqueness is not important)
*/

int totalPalindromicSubsequences(string s){
	int n { (int) s.size() };
	vector<vector<int>> dp(n, vector<int>(n));
	for(int i { 0 }; i < n; i++) dp[i][i] = 1;
	for(int i { 1 }; i < n; i++){
		if(s[i] == s[i-1]) dp[i-1][i] = 1;
	}
	for(int i { n - 2 }; i >= 0; i--){
		for(int j { 1 }; j < n; j++){
			if(s[i] == s[j]){
				dp[i][j] = 1 + dp[i][j-1] + dp[i+1][j];
			} else {
				dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
			}
		}
	}
	return dp[0][n-1];
}

int main() {
	string s; cin >> s;
	cout << totalPalindromicSubsequences(s) << endl;
	return 0;

