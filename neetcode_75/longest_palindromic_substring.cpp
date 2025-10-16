#include <iostream>
#include <unordered_set>
using namespace std;

// there is an O(1) space solution as well - review
string longestPalindrome(string s) {
	int n = s.size();		
  vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[i][j] is whether from substring from i to j is a palindrome
	string ans = s.substr(0, 1);
	for(int i = 0; i < n; i++){
		dp[i][i] = true;
		if(i >= 1 and s[i] == s[i-1]){
			dp[i-1][i] = true;
			ans = s.substr(i-1, 2);
		}
	}

	for(int i = 2; i <= n; i++){ // order of the loops is important!
		for(int j = 0; j + i <= n; j++){
			int l = j;
			int r = j + i - 1;
			if(dp[l + 1][r - 1] and s[l] == s[r]){
				dp[l][r] = true;
				string cur = s.substr(l, r - l + 1);
				if(cur.size() > ans.size()){
					ans = cur;
				}
			}
		}
	}
	return ans;
}

int main() {
	string s; cin >> s;
	cout << longestPalindrome(s) << endl;
	return 0;
}
