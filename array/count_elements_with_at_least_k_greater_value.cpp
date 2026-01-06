#include <iostream>
using namespace std;

int countElements(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int count = 0;
		for(int i = 0; i < n; i++){
				int j = i + 1;
				while(j < n and nums[j] == nums[i]) j++;
				int dup = j - i;
				int greater = n - i - dup;
				if(greater >= k) count += dup;
				i = j - 1;
		}
		return count;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	int k; cin >> k;
	cout << countElements(v, k) << endl;
	return 0;
}
