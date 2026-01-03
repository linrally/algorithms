#include <iostream>
using namespace std;

int countSubstrings(string s) {
	int n = s.size();
	vector<vector<bool>> dp(n, vector<bool>(n));
	int count = 0;
	for(int i = 0; i < n; i++){
		dp[i][i] = true; count++;
		if(i < n - 1 and s[i] == s[i+1]){
			dp[i][i+1] = true;
			count++;
		}
	}
	for(int k = 3; k <= n; k++){
		for(int i = 0; i < n - k + 1; i++){
			int j = i + k - 1;
			if(s[i] == s[j] and dp[i+1][j-1]){
				dp[i][j] = true;
				count++;
			}
		}
	}
	return count;
}

int main() {
	string s; cin >> s;
	cout << countSubstrings(s) << endl;
	return 0;
}
