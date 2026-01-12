#include <iostream>
using namespace std;

static vector<unsigned long long> mem(1 << 16);

void populate(){
	for(int i = 0; i < (1 << 16); i++){
		int x = i;
		for(int b = 0; b < 16; b++){
			mem[i] = (mem[i] << 1) | (x & 1);
			x >>= 1;
		}
	}
}

unsigned long long reverse(unsigned long long x){
	unsigned long long mask = 0xFFFF;
	return (mem[x & mask] << 48) | 
				 (mem[(x >> 16) & mask] << 32) | 
				 (mem[(x >> 32) & mask] << 16) | 
				 (mem[x >> 48]);
}

int main() {
	populate();
	unsigned long long x; cin >> x;
	cout << reverse(x) << endl;
	return 0;
}
