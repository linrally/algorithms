#include <iostream>
using namespace std;

// maximum reachable length
bool canJump(vector<int>& nums) {
	int n = nums.size();
	if(n == 1) return true;
	int reachable = 0;
	for(int i = 0; i<n; i++){
		if(reachable >= i){
			reachable = max(nums[i] + i, reachable);
		}
	}
	return reachable >= n - 1;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << canJump(v) << endl;
	return 0;
}
