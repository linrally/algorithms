#include <iostream>
#include <iomanip>

using namespace std;

// Naive median finding on an unsorted array is O(nlogn). Sort the array in O(nlogn) and find the n/2-th element.
// We can use an alternative divide & conquer approach to achieve O(n) runtime. Called "quickselect."
int find(vector<int> &A, int k){
	int pivot = rand() % A.size();
	vector<int> less, greater, equal;
	for(int x: A){
		if(x == A[pivot]) equal.push_back(x);
		else if (x < A[pivot]) less.push_back(x);
		else greater.push_back(x);
	}

	if(k < less.size()) return find(less, k);
	else if(k >= less.size() + equal.size()) return find(greater, k - less.size() - equal.size());
	else return equal[0];
}

float median(vector<int> &A){ // unsorted array
	int n = A.size();
	if(n % 2 == 1) return find(A, n/2);
	else return (find(A, n/2) + find(A, n/2 - 1)) / 2.0;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << setprecision(4) << median(v) << endl;
	return 0;
}
