#include <iostream>
using namespace std;

static bool comp(vector<int> a, vector<int> b){
	return a[0] < b[0];
}

bool canAttendMeetings(vector<vector<int>>& intervals) {
	int n = intervals.size();	
	sort(intervals.begin(), intervals.end(), comp);	
	for(int i = 1; i < n; i++){
		vector<int> iv = intervals[i];
		vector<int> piv = intervals[i-1];
		if(iv[0] < piv[1]) return false;
	}
	return true;
}

int main() {
	int N; 
	cin >> N;
	vector<vector<int>> v(N, vector<int>(2));
	for(int i = 0; i < N; i++){
	    cin >> v[i][0] >> v[i][1];
	}
	cout << canAttendMeetings(v) << endl;
	return 0;
}
