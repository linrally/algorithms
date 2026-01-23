#include <iostream>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(0, 1);

int uniformRandom(int lower_bound, int upper_bound){
	int range = upper_bound - lower_bound - 1;		
	int num;
	do {
		num = 0;
		for(int i = 0; (1 << i) < range; i++){
			num |= distrib(gen) << i;
		}
	} while (num >= range); 
	return num + lower_bound;
}

int main() {
	int a, b; cin >> a >> b;
	for(int i = 0; i < 10; i++) cout << uniformRandom(a, b) << endl;
	return 0;
}
