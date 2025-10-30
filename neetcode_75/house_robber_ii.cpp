#include <vector>
#include <iostream>
using namespace std;

int rob_subarray(int start, int end, vector<int> &nums){
		int n = end - start + 1;
		if (n == 0) return 0;
		if (n == 1) return nums[start];
		vector<int> dp(n);
		dp[0] = nums[start];
		dp[1] = max(nums[start], nums[start + 1]);
		for(int i = 2; i < n; i++){
				dp[i] = max(dp[i-2] + nums[start + i], dp[i-1]);
		}
		return dp[n-1];
}

int rob(vector<int>& nums) {
		int n = nums.size();
		if(n == 1) return nums[0];
		return max(rob_subarray(0, n - 2, nums), rob_subarray(1, n-1, nums));
}

int main(){
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << rob(v) << endl;
}
