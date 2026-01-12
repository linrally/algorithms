#include <iostream>
using namespace std;

// long long is guaranteed 64 bit
void swap(unsigned long long &x, int i, int j){
	if((x & (1LL << i)) == (x & (1LL << j))) return;
	x ^= (1LL << i) | (1LL << j);
}

int main() {
	unsigned long long x; cin >> x;
	int i, j; cin >> i >> j;
	swap(x, i, j);
	cout << x << endl;
	return 0;

}
