#include <iostream>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	int n = intervals.size();	
	vector<vector<int>> res;
	int i = 0;
	while(i < n and intervals[i][1] < newInterval[0]){
		res.push_back(intervals[i]);
		i++;
	}
	int nl = newInterval[0], nr = newInterval[1];
	while(i < n and intervals[i][0] <= newInterval[1]){
		nl = min(intervals[i][0], nl);
		nr = max(intervals[i][1], nr);
		i++;
	}
	res.push_back({nl, nr});
	while(i < n){
		res.push_back(intervals[i]);
		i++;
	}
	return res;
}

int main() {
	int n; cin >> n;
	vector<vector<int>> v;
	for(int i = 0; i<n; i++){
		int x, y; cin >> x >> y;
		v.push_back({x,y});
	}
	int nx, ny; cin >> nx >> ny;
	vector<int> newInterval = {nx, ny};
	vector<vector<int>> res = insert(v, newInterval);
	for(auto a: res){
		for(int x: a){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
