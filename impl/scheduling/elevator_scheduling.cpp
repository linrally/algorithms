#include <iostream>
using namespace std;

// Elevator scheduling is also used for disk scheduling
// Want to minimize the total seek time (time to move disk arm to the track where data is located)

struct Request{
	int source {};
	int dest {};
};

using Floor = int;

vector<Floor> LOOKPickup(vector<Request> requests, Floor cur, int direction){ // pickup order only
	vector<Floor> left, right, pickup;
	for(Request r: requests){
		if (r.source < cur) left.push_back(r.source);
		else right.push_back(r.source);
	}

	sort(left.begin(), left.end(), greater<Floor>()); 
	sort(right.begin(), right.end());

	if(direction == 1){ // up
		for (Floor f : right)
			pickup.push_back(f);
		for (Floor f : left)
			pickup.push_back(f);
	} else { // down
		for (Floor f : left)
			pickup.push_back(f);
		for (Floor f : right)
			pickup.push_back(f);
	}

	return pickup;
}

int main() {
	int N; cin >> N;
	vector<Request> requests(N);
	for(int i = 0; i < N; i++) cin >> requests[i].source >> requests[i].dest;
	Floor cur; cin >> cur;
	int direction; cin >> direction;
	vector<Floor> res = LOOKPickup(requests, cur, direction);
	for(Floor f: res) cout << f << " ";
	cout << endl;
	return 0;
}
