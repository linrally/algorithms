#include <iostream>
using namespace std;

// can do this with hashset but two pointers approach is best
// sort nums
// iterate over i; set pointers l and r to be either end of the subset right of i
// use two pointers to find sum equal to -nums[i]
// l++ to increase and r-- to decrease sum
vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	for(int i = 0; i + 1 < n; i++){
		if(i > 0 and nums[i] == nums[i-1]) continue;
		int needed = -1*nums[i];
		int l = i + 1;
		int r = n - 1;
		int sum;
		while (l < r){
			sum = nums[l] + nums[r];
			if(sum > needed){	
				r--;
			} 
			else if(sum < needed){
				l++;
			}
			else {
				res.push_back({nums[i], nums[l], nums[r]}); // i < j < k distinct
				while (l < r && nums[l] == nums[l + 1]) l++;  // skip duplicates of l and r next to in sorted order
        while (l < r && nums[r] == nums[r - 1]) r--;
				l++;
				r--;
			} 
		}
	}
	return res;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	vector<vector<int>> nums = threeSum(v);
	for(auto r:nums){
		for(int x:r){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
