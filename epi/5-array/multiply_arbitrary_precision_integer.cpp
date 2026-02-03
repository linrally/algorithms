#include <iostream>
using namespace std;

vector<int> multiplyArbitraryPrecisionInteger(vector<int> a, vector<int> b){
	int n = a.size();
	int m = b.size();
	vector<int> sum (m + n);	
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			sum[i + j + 1] += a[i] * b[j];	
			sum[i + j] += sum[i + j + 1] / 10; // propagate carry on to next digit
			sum[i + j + 1] %= 10; // modulo since we carried forward
		}
	}
	// remove leading zeros
	auto it = sum.begin();
	while(*it == 0) it++;
	vector<int> res(sum.end() - it);
	copy(it, sum.end(), res.begin());
	return res;
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for(int i = 0; i<N; i++){
		cin >> a[i];
	}
	int M; cin >> M;
	vector<int> b(M);
	for(int i = 0; i<M; i++){
		cin >> b[i];
	}
	vector<int> res = multiplyArbitraryPrecisionInteger(a, b);
	for(int x: res) cout << x << " ";
	cout << endl;
	return 0;
}
