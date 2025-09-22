#include <iostream>
using namespace std;

// O(n) single pass
// Kadane's Algorithm, dynamic programming
int maxSubArray(vector<int> &nums){
	int n = nums.size();
	int global_max = nums[0];	
	int current_max = nums[0]; // maximum subarray ending at current position
	for(int i = 1; i < n; i++){
		current_max = max(nums[i], current_max + nums[i]);	
		global_max = max(current_max, global_max);
	}
	return global_max;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << maxSubArray(v) << endl;
	return 0;
}
