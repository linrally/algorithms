#include <iostream>
using namespace std;

void evenOdd(vector<int> &a){
	int even = 0;
	int odd = a.size() - 1;
	while(even < odd){
		if(a[even] % 2 == 0){
			even++;
		} else {
			swap(a[even], a[odd]);	
			odd--;
		}
	}
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	evenOdd(v);
	for(int x: v) cout << x << " ";
	cout << endl;
	return 0;
}
