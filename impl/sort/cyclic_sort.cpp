#include <iostream>
using namespace std;

template <typename T>
void cyclic_sort(vector<T> &v){ 
	// sort an array where the elements are [1 ... n] without duplicates
	// O(n) runtime
	int n = v.size();
	int i = 0;
	while(i < n){
		if(v[v[i] - 1] != v[i]){
			swap(v[i], v[v[i] - 1]);
		} else {
			i++;
		}
	}
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cyclic_sort(v);
	for(int i = 0; i<N; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
