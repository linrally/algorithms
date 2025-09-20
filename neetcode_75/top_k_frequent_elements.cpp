#include <iostream>
using namespace std;

// ideas
// 1. sorting O(nlogn) with a custom comparator
// 2. construct a min heap of frequency
// optimal solution is actually Horare's Algorithm (used for kth something": kth smallest, kth largest, kth most frequent, kth less frequent, etc.)
static bool compare(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second; // true if a before b (diff from pq)
}

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int,int> f;
	for(int x: nums){
		f[x]++;
	}
	vector<pair<int,int>> h(f.begin(), f.end());
	make_heap(h.begin(), h.end(), compare);
	vector<int> res;
	while(k-- > 0){
		pop_heap(h.begin(), h.end(), compare); // moves max element to back an reheapify n-1, allows us to remove last element
		pair<int,int> top = h.back();
		res.push_back(top.first);
		h.pop_back();
	}
	return res;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}		
	int k; cin >> k;
	vector<int> res;
	res = topKFrequent(v, k);
	for(int x: res){
		cout << x << " ";
	}
	return 0;
}
