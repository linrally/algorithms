#include <iostream>
using namespace std;

int rev(int x){
	int res = 0;
	while(x != 0){
			res *= 10;
			res += (x % 10);
			x /= 10;
	}
	return res;
}

int mirrorDistance(int n) {
	return abs(n - rev(n));
}

int main() {
	int n; cin >> n;
	cout << mirrorDistance(n) << endl;
	return 0;
}
