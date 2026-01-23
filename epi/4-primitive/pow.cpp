#include <iostream>
using namespace std;

double pow(double x, int y){
	if(y == 0) return 1.0;
	double tmp = pow(x, y / 2);
	if(y % 2 == 0) return tmp * tmp;
	else return tmp * tmp * x;
}

// iterative approach to avoid overhead of function calls
double pow_it(double x, int y){
	double res = 1.0;
	if(y < 0){
		y = -y;
		x = 1.0 / x;
	}
	while(y){
		if(y & 1){
			res *= x;
		}
		x *= x;
		y >>= 1;
	}
	return res;
}

int main() {
	double x; cin >> x;
	int y; cin >> y;
	cout << pow_it(x, y) << endl;
	return 0;
}
