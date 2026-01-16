#include <iostream>
using namespace std;

unsigned int findClosestIntegerWithSameWeight(unsigned int x){ 
	// swap the first 2 bits that differ, provably optimal
	for(int i = 0; i < 31; i++){ // LSB upward
		if(((x >> i) & 1) ^ ((x >> (i+1)) & 1) ){
			x ^= (1 << i) | (1 << (i+1)); // swap
			break;
		}
	}
	return x;
}

int main() {
	unsigned int x; cin >> x;
	cout << findClosestIntegerWithSameWeight(x) << endl;
	return 0;
}
