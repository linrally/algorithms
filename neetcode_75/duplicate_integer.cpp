#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
	int n = nums.size();
	unordered_set<int> s;
	for(int i = 0; i<n; i++){
		s.insert(nums[i]);
		if(s.size() < i + 1) return true;
	}
	return false;
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	cout << containsDuplicate(v) << endl;
	return 0;
}
