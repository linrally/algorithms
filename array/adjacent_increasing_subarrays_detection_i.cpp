#include <iostream>
using namespace std;

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
	int n = nums.size();		
	int prev = 0;
	int cur = 1;
	for(int i = 1; i<n; i++){
		if(nums[i] > nums[i-1]){
			cur++;	
		} else {
			prev = cur;
			cur = 1;
		}
		if(prev >= k and cur >=k) return true;
		if(prev >= 2*k or cur >= 2*k) return false;
	}
	return false;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	int K; cin >> K;
	cout << hasIncreasingSubarrays(v, K) << endl;
	return 0;
}
