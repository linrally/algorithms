#include <iostream>
using namespace std;

// This is a different problem than "2484. Count Palindromic Subsequences."
// Textbook problem of counting nondistinct palindromic subsequences in a string.
int countPalindromes(string s) {
	int n = s.size();		
	vector<vector<int>> dp(n, vector<int>(n)); // dp[i][j] is the number of palidnromic subsequences in s[i...j]
	for(int i = 0; i < n; i++){
		dp[i][i] = 1;
	}
	for(int k = 2; k <= n; k++){
		for(int i = 0; i < n - k + 1; i++){
			int j = i + k - 1;
			if(s[i] == s[j]){
				dp[i][j] = 1  + dp[i+1][j] + dp[i][j-1];
			} else {
				dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			}
		}
	}
	return dp[0][n-1];
}

int main() {
	string s; cin >> s;
	cout << countPalindromes(s) << endl;
	return 0;
}
