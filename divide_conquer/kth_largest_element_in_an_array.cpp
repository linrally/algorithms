#include <iostream>
using namespace std;

// quickselect
int find(vector<int> &A, int k){
	int pivot = rand() % A.size();
	vector<int> less, greater, equal;
	for(int x: A){
		if(x == A[pivot]) equal.push_back(x);
		else if (x < A[pivot]) less.push_back(x);
		else greater.push_back(x);
	}

	if(k < less.size()) return find(less, k);
	else if(k >= less.size() + equal.size()) return find(greater, k - less.size() - equal.size());
	else return equal[0];
}

int findKthLargest(vector<int>& nums, int k) {
	return find(nums, nums.size() - k);
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	int k; cin >> k;
	cout << findKthLargest(v, k) << endl;
	return 0;
}
