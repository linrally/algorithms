#include <iostream>
using namespace std;

// number of set bits in n
// 1011
int hammingWeight(int n) {	
	int count = 0;
	for(int i = 0; i < 32; i++){
		if ((n & (1 << i)) > 0) count++;
	}
	return count;
}

int main() {
	int N; cin >> N;
	cout << hammingWeight(N) << endl;
	return 0;
}
