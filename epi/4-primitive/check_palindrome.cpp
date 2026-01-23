#include <iostream>
using namespace std;

bool checkPalindrome(int x){
	int n = static_cast<int>(log10(x));
	int cur = x;
	int exp = static_cast<int>(pow(10, n));
	for(int i = 0; i <= n/2; i++){
		if(cur % 10 != x / exp) return false;
		x /= 10;
		exp /= 10;
	}
	return true;
}

int main() {
	int x; cin >> x;
	cout << checkPalindrome(x) << endl;
	return 0;
}
