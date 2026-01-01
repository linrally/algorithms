#include <iostream>
using namespace std;

// binary search on the predicate: (# of elements <= x) <= x
// find the minimum value where it is not true
int findDuplicate(vector<int>& nums) {
	int n = nums.size();
	int l = 1;
	int r = n;
	int res = INT_MAX;
	while (l <= r){
		int mid = (l + r) / 2;
		int countLeq = 0 ;
		for(int x: nums) if (x <= mid) countLeq++;
		if(countLeq <= mid) l = mid + 1;
		else {
			res = min(mid,  res); // this is a candidate
			r = mid - 1; // look on the left
		}
	}
	return res;
}

// there is an O(n) solution that uses Floyd's tortoise and hare

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << findDuplicate(v) << endl;
	return 0;
}
