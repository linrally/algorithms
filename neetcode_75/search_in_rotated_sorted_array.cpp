#include <iostream>
using namespace std;

int search(vector<int>& nums, int target) {
	int n = nums.size();
	int l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2;
		if(target == nums[m]){
			return m;
		}
		if (nums[m] >= nums[0]) {
			// mid is on the left segment
			if (target >= nums[0] && target > nums[m])
				l = m + 1;
			else if(target >= nums[0] && target < nums[m])
				r = m - 1;
			else 
				l = m + 1;
		} else {
			// mid is on the right segment
			if (target < nums[0] && target > nums[m])
				l = m + 1;
			else if (target < nums[0] && target < nums[m])
				r = m - 1;
			else 
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
	int t; cin >> t;
	cout << search(v, t) << endl;
	return 0;
}
