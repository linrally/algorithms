#include <iostream>
using namespace std;

int countBits(unsigned int x){
	short count = 0;
	while(x){
		count += (x & 1);
		x >>= 1;
	}
	return count;
}

int main() {
	int x; cin >> x;
	cout << countBits(x) << endl;
	return 0;
}
