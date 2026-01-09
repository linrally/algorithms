#include <iostream>
using namespace std;

using Floor = int;

// First Come First Serve (FCFS)
vector<Floor> FCFS(vector<Floor> requests, Floor cur) {
	return requests;
}

// Shortest Seek Time First (SSTF)
// More optimal for total time, but may result in starvation
vector<Floor> SSTF(vector<Floor> requests, Floor cur){
	vector<Floor> stops;
	vector<Floor> remaining = requests;
	while(remaining.size() > 0){
		int minDist = abs(cur - remaining[0]);
		int minIdx = 0;
		for(int i = 1; i < remaining.size(); i++){
			if(abs(cur - remaining[i]) < minDist){
				minIdx = i;
				minDist = abs(cur - remaining[i]);
			}
		}
		stops.push_back(remaining[minIdx]);
		cur = remaining[minIdx];
		remaining.erase(remaining.begin() + minIdx);
	}
	return stops;
}

// SCAN. Move in one direction, servicing all requests until reaching the end, then reverse.
// https://en.wikipedia.org/wiki/Elevator_algorithm
const int MAX_FLOOR = 100;
vector<Floor> SCAN(vector<Floor> requests, Floor cur){ // initial direction technically matters here, but omitted for simplicity
  vector<Floor> path;
  vector<Floor> up, down;

  path.push_back(cur);

  for (Floor f : requests) {
    if (f >= cur) up.push_back(f);
    else down.push_back(f);
  }

  sort(up.begin(), up.end());
  sort(down.begin(), down.end(), greater<Floor>());

  for (Floor f : up) {
    if (path.back() != f)
      path.push_back(f);
    cur = f;
  }

  if (cur != MAX_FLOOR) { // go to top
    cur = MAX_FLOOR;
    path.push_back(cur);
  }

  for (Floor f : down) {
    if (path.back() != f)
      path.push_back(f);
    cur = f;
  }

  return path;
}


// LOOK. Instead of going all the way to the end, reverse direction at the last request in each direction.
// https://en.wikipedia.org/wiki/LOOK_algorithm
vector<Floor> LOOK(vector<Floor> requests, Floor cur){
  vector<Floor> path;
  vector<Floor> up, down;

  path.push_back(cur);

  for (Floor f : requests) {
    if (f >= cur) up.push_back(f);
    else down.push_back(f);
  }

  sort(up.begin(), up.end());
  sort(down.begin(), down.end(), greater<Floor>());

  for (Floor f : up) {
    if (path.back() != f)
      path.push_back(f);
    cur = f;
  }

  for (Floor f : down) {
    if (path.back() != f)
      path.push_back(f);
    cur = f;
  }

  return path;

}

int main() {
	int N; cin >> N;
	vector<Floor> requests(N);
	for(int i = 0; i < N; i++) cin >> requests[i];
	Floor cur; cin >> cur;
	vector<Floor> res = LOOK(requests, cur);
	for(Floor f: res) cout << f << " ";
	cout << endl;
	return 0;
}
