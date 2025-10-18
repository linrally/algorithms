#include <iostream>
using namespace std;

int rob(vector<int>& nums) {
	int n = nums.size();
	if(n == 1) return nums[0];
	if(n == 2) return max(nums[0], nums[1]);
	vector<int> dp(n);
	for(int i = 0; i < n; i++){
		if(i == 0){
			dp[i] = nums[0]; // can either rob 0 or 1
		} else if(i == 1){
			dp[i] = max(nums[0], nums[1]);
		} else {
			dp[i] = max(dp[i-2] + nums[i], dp[i-1]); // either take adjacent house or the one before it + current
		}
	}
	return dp[n-1];
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << rob(v) << endl;
	return 0;
}
