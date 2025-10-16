#include <iostream>
using namespace std;

int maxIncreasingSubarrays(vector<int>& nums) {
	int n = nums.size();	
	int mx = 0;
	int prev = 0;
	int cur = 1;
	for(int i = 1; i < n; i++){
		if(nums[i] > nums[i-1]){
			cur++;
		} else {
			mx = max(max(min(prev,cur), mx), cur/2);
			prev = cur;
			cur = 1;
		}
	}
	mx = max(max(min(prev,cur), mx), cur/2);
	return mx;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << maxIncreasingSubarrays(v) << endl;
	return 0;
}
