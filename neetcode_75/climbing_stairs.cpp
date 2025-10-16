#include <iostream>
using namespace std;

int climbStairs(int n){
	vector<int> dp(n + 1);
	dp[0] = 1;
	for(int i = 1; i<n + 1; i++){
		if(i == 1){
			dp[i] = dp[i-1];
		} else {
			dp[i] = dp[i-1] + dp[i-2];
		}
	}
	return dp[n];
}

int main() {
	int n; cin >> n;
	cout << climbStairs(n) << endl;
	return 0;
}
