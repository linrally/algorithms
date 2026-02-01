#include <iostream>
using namespace std;

enum Color { red = 0, white = 1, blue = 2 };

// O(2n)
void dutchFlagPartition(int pivot_index, vector<Color> &a){
	int n = a.size();										
	int greater = n - 1;
	int less = 0;
	while(less < greater){
		if(a[less] < a[pivot_index]){
			less++;
		} else {
			swap(a[less], a[greater]);
			greater--;
		}
	}
	int eq = less;
	greater = n - 1;
	while(eq < greater){
		if(a[eq] == a[pivot_index]){
			eq++;
		} else {
			swap(a[eq], a[greater]);
			greater--;
		}
	}
}

// O(n)
void dutchFlagPartitionOpt(int pivot_index, vector<Color> &a){
	int n = a.size();
	int i = 0, j = 0, k = n - 1;
	while(j < k){
		if(a[j] < a[pivot_index]){
			swap(a[j], a[i]);
			i++;
			j++;
		} else if (a[j] > a[pivot_index]){
			swap(a[j], a[k]);
			k--;
		} else {
			j++;
		}
	}
}

int main() {
	int N; cin >> N;
	vector<Color> v(N);
	for(int i = 0; i<N; i++){
		int x; cin >> x;
		v[i] = (Color)x;
	}
	int k; cin >> k;
	dutchFlagPartitionOpt(k, v);
	for(int x: v) cout << x << " ";
	cout << endl;
	return 0;
}
