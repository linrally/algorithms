#include <iostream>
#include <unordered_map>
using namespace std;

static int h(int x, int y){
	return (int)1e5 * (x + 300) + (y + 300); // casting to int is important for avoiding rounding errors
}

static pair<int,int> decode(int h){
	int x = (h / (int)1e5) - 300;
	int y = (h % (int)1e5) - 300;
	return {x, y};
}

vector<pair<int,int>> moves = {{1, 2}, {-1, 2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {-1, -2}, {1, -2}};

int minKnightMoves(int x, int y) {
	unordered_map<int, int> dist;
	dist[h(0, 0)] = 0;
	queue<int> q;
	q.push(h(0, 0));
	while(not q.empty()){
		int hash = q.front(); q.pop();
		if(hash == h(x, y)) break;
		auto cur = decode(hash);
		for(auto &p: moves){
			int nx = cur.first + p.first;
			int ny = cur.second + p.second;
			if(dist.contains(h(nx, ny))) continue;
			if(nx > 300 or nx < -300 or ny > 300 or ny < -300) continue;
			q.push(h(nx, ny));
			dist[h(nx, ny)] = dist[hash] + 1;
		}
	}
	if(not dist.contains(h(x, y))) return -1;
	return dist[h(x, y)];
}

int main() {
	int x, y; cin >> x >> y;
	cout << minKnightMoves(x, y) << endl;
	return 0;
}
