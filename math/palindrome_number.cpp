#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int x) {
	if(x < 0) return false;
    if(x == 0) return true;
	int s = log10(x);			
	for(int i = 0; i < s; i++){
		int ld = x / (int)pow(10, s - i) % 10;
		int rd = (x / (int)pow(10,i)) % 10;
		if (ld != rd) return false;
	}
    return true;
}

int main() {
	int N; cin >> N;
	cout << isPalindrome(N) << endl;
	return 0;
}
