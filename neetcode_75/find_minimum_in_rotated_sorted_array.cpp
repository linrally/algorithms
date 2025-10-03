#include <iostream>
using namespace std;

int findMin(vector<int>& nums){
	int n = nums.size();
	int l = 0;
	int r = n - 1;
	if (nums[l] <= nums[r]) return nums[l];
	while(l <= r){
		int m = (l + r) / 2;
		if(m < n - 1 and nums[m] > nums[m+1]) return nums[m+1];
		if(m > 0 and nums[m - 1] > nums[m]) return nums[m];
		if(nums[m] > nums[0]){
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return -1;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << findMin(v) << endl;
	return 0;
}
