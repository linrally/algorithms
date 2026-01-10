#include <iostream>
using namespace std;

short bruteForce(unsigned long long x){ // O(n)
	short res = 0;
	while(x){
		res ^= (x & 1);
		x >>= 1;
	}
	return res;
}

short eraseLowestSetBit(unsigned long long x){ // O(k), k = # of set bits
	short res = 0;
	while(x){
		x = x & (x-1);
		res ^= 1;
	}
	return res;
}

static vector<short> mem(1 << 16);
void populate(){
	for(int i = 0; i < (1 << 16); i++){
		mem[i] = eraseLowestSetBit(i);
	}
}
short cache(unsigned long long x){
	unsigned long long mask = 0xFFFF;	
	return mem[x >> (3 * 16)] ^ mem[(x >> (2 * 16)) & mask] ^ mem[(x >> 16) & mask] ^ mem[x & mask]; 
}

short parityXOR(unsigned long long x){
	x ^= (x >> 32);
	x ^= (x >> 16);
	x ^= (x >> 8);
	x ^= (x >> 4);
	x ^= (x >> 2);
	x ^= (x >> 1);
	return x & 0x1;
}

int main() {
	unsigned long long x; cin >> x;
	// cout << bruteForce(x) << endl;
	// cout << eraseLowestSetBit(x) << endl;
	// populate(); cout << cache(x) << endl;
	cout << parityXOR(x) << endl;
	return 0;
}
