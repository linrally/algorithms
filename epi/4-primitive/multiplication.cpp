#include <iostream>
using namespace std;

unsigned int add(unsigned int a, unsigned int b){
	while(b){
		unsigned int carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	return a;
}

unsigned int multiply(unsigned int x, unsigned int y){
	unsigned int sum = 0;
	while(y){
		if(y & 1){
			sum = add(sum, x);
		}
		x <<= 1;
		y >>= 1;
	}
	return sum;
}

int main() {
	unsigned int x, y; cin >> x >> y;
	cout << multiply(x, y) << endl;
	return 0;
}
