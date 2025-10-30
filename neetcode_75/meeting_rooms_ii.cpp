#include <iostream>
#include <vector>

using namespace std;

static bool comp(vector<int> &a, vector<int> &b){
		if(a[0] == b[0]) return a[1] < b[1];
		return a[0] < b[0];
}

int minMeetingRooms(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), comp); // sort by increasing start
		vector<vector<int>> classrooms;  
		priority_queue<int,vector<int>,greater<int>>pq; // holds the finish time of all currently happening meeting
		int mx = 0;
		for(auto &iv: intervals){
				int start = iv[0], end = iv[1];
				if(pq.empty() or pq.top() > start){
						pq.push(end);
				} else {
						pq.pop();
						pq.push(end);
				}
				mx = max((int)pq.size(), mx);
		}
		return mx;
}

int main(){
	int N; 
	cin >> N;
	vector<vector<int>> v(N, vector<int>(2));
	for(int i = 0; i < N; i++){
	    cin >> v[i][0] >> v[i][1];
	}
	cout << minMeetingRooms(v) << endl;
}
