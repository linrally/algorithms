#include <iostream>
using namespace std;

// cannot use the division operator
// prefix and suffix O(n), but not O(1) space
// can make O(1) by not storing in an array but having running pointers?
// 1 2 6 24 (pre)
// 4 12 24 24 suf)
// suf 0 should go to 2
// pre 0 should go to 1
vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int> res(n, 1);	
	int pre = 1;
	int suf = 1;
	for(int i = 0; i<n; i++){
		pre *= nums[i];
		suf *= nums[n-i-1];
		if(i + 1 < n) res[i+1] *= pre;
		if(n - i - 2 >= 0) res[n-i-2] *= suf;
	}
	return res;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	vector<int> r = productExceptSelf(v);
	for(int x:r){
		cout << x << " ";
	}
	return 0;
}
