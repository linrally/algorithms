#include <iostream>
using namespace std;

struct Rect {
	int x, y, w, h;
	// (x, y) is bottom left vertex
};

bool intervalIntersect(int a, int b, int c, int d){
	if (a <= d && c <= b) return true;
	return false;
}

Rect intersectRectangle(const Rect& a, const Rect& b){
	if(not (intervalIntersect(a.x, a.x + a.w, b.x, b.x + b.w) and intervalIntersect(a.y, a.y + a.h, b.y, b.y + b.h))) return {0, 0, -1, -1};
	int rx = max(a.x, b.x);
	int ry = max(a.y, b.y);
	int rw = min(a.x + a.w, b.x + b.w) - max(a.x, b.x);
	int rh = min(a.y + a.h, b.y + b.h) - max(a.y, b.y);
	return {rx, ry, rw, rh};
}

int main() {
	Rect a, b;
	cin >> a.x >> a.y >> a.w >> a.h;
	cin >> b.x >> b.y >> b.w >> b.h;
	Rect res = intersectRectangle(a, b);
	cout << res.x << " " << res.y << " " << res.w << " " << res.h << endl;
	return 0;
}
