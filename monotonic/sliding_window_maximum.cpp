#include <iostream>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int n = nums.size();	
	deque<int> dq;
	vector<int> res(n - k + 1);
	for(int i = 0; i < k; i++){
		while(not dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
		dq.push_back(i);
	}
	res[0] = nums[dq.front()];
	for(int i = k; i < n; i++){
		while(not dq.empty() and dq.front() < i - k + 1) dq.pop_front();
		while(not dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
		dq.push_back(i);
		res[i - k + 1] = nums[dq.front()];
	}
	return res;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	int K; cin >> K;
	vector<int> res = maxSlidingWindow(v, K);
	for(int x: res) cout << x << " ";
	cout << endl;
	return 0;
}
