#include <iostream>
using namespace std;

unsigned int division(unsigned int x, unsigned int y){
	unsigned int k = 32; // count downward from 32, find max 2^k * y <= x
	unsigned long long power = (unsigned long long)y << k; // need to cast before shift
	unsigned int result = 0;
	while(x >= y){ // the next 2^k is guaranteed to be smaller
		while(power > x){
			power >>= 1;
			k--;
		}
		result += 1 << k;
		x -= power;
	}
	return result;
}

int main() {
	unsigned int x, y; cin >> x >> y;
	cout << division(x, y) << endl;
	return 0;
}
