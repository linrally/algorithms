#include <iostream>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	vector<int> dp(n);
	for(int i = 0; i<n; i++){
		if(i == 0 or i == 1){
			dp[i] = cost[i];
		} else {
			dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
		}
	}
	return min(dp[n-1], dp[n-2]);
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << minCostClimbingStairs(v) << endl;
	return 0;
}
