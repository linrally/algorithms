#include <iostream>
using namespace std;

bool comp(vector<int> a, vector<int> b){
	if(a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), comp);	
	vector<int> t = intervals[0];
	vector<vector<int>> res;
	for(int i = 1; i < n; i++){
		vector<int> c = intervals[i];	
		if(c[0] <= t[1]){
			t[1] = max(t[1], c[1]);
		} else {
			res.push_back(t);	
			t = c;
		}
	}
	res.push_back(t);	
	return res;
}

int main() {
	int n; cin >> n;
	vector<vector<int>> v;
	for(int i = 0; i < n; i++){
		int l, r; cin >> l >> r;
		v.push_back({l, r});
	}
	vector<vector<int>> res = merge(v);
	for(auto a: res){
		for(int x: a){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
