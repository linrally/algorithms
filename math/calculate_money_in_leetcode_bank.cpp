#include <iostream>
using namespace std;

// 1 + 2 + 3 + 4 + 5 + 6 + 7
// 2 + 3 + 4 + 5 + 6 + 7 + 8
// 3 + 4 + 5 
int totalMoney(int n) {
	int total = 0; 
	for(int i = 1; i<=7; i++){
		if(i <= n % 7){
			int it = n / 7 + 1; 
			total += (it)*(it+1)/2 + (i-1) * it;
		} else if (n > 7){
			int it = n / 7;
			total += (it)*(it+1)/2 + (i-1) * it;
		}
	}
	return total;
}

int main() {
	int n; cin >> n;
	cout << totalMoney(n) << endl;
	return 0;
}
