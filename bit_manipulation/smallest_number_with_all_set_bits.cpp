#include <iostream>
using namespace std;

int smallestNumber(int n) {
		int k = ceil(log2(n));
		if(1 << k == n) k += 1;
		int nk = 1 << k;
		return nk - 1;
}

int main() {
	int N; cin >> N;
	cout << smallestNumber(N) << endl;
	return 0;
}
