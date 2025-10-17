#include <iostream>
using namespace std;

int singleNumber(vector<int>& nums) {
	int n = nums.size();		
	int x = 0;
	for(int i = 0; i < n; i++){
		x = x ^ nums[i];
	}
	return x;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << singleNumber(v) << endl;
	return 0;
}
