#include <iostream>
using namespace std;

// for each i, res[i] has the # of 1s in the binary rep of i
// apparently we can use dynamic programming here
// 0    0
// 1    1
// 10   1
// 11   2
// 100  1
// 101  2
// 110  2
// 111  3
// 1000 1
// res[7] = res[4] + res[2] + res[1] = res[4] + res[3]
// res[6] = res[4] + res[2] 
vector<int> countBits(const int n) {
	if(n == 0) return {0};
	vector<int> res(n + 1);	
	res[0] = 0;
	res[1] = 1;
	for(int i = 2; i<=n; i++){
		// find the closest power of 2
		int k = 1 << (int)log2(i);
		if(i == k) res[i] = 1;
		res[i] = res[k] + res[i - k];
	}
	return res;
}

int main() {
	int N; cin >> N;
	for(int x: countBits(N)){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
