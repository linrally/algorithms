#include <iostream>
using namespace std;

// model as a lienar problem x = y + (b - a), x >= xeq, y >= yeq
// solution for minimum y is max(yeq, xeq - (b - a))
long long minSum(vector<int>& nums1, vector<int>& nums2) {
	long long a = 0, b = 0;
	long long xeq = 0, yeq = 0;
	for(int e:nums1){
		if(e == 0) xeq++;
		else a+=e;
	}
	for(int e:nums2){
		if(e == 0) yeq++;
		else b+=e;
	}
	if(yeq == 0 and xeq == 0) return (a == b) ? a : -1;
	else if (yeq == 0) return (b - a >= xeq) ? b : -1;
	else if (xeq == 0) return (a - b >= yeq) ? a : -1;

	long long S1 = a + xeq;
	long long S2 = b + yeq;
	return max(S1, S2);
}

int main() {
	int N; cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	int M; cin >> M;
	vector<int> B(M);
	for(int i = 0; i < M; i++) cin >> B[i];
	cout << minSum(A, B) << endl;
	return 0;
}
