#include <iostream>
using namespace std;

// returns index of first element > x (highest position that the element could be inserted without breaking sorted order)
// ex: in a binary search for 5 
//         v-- lower bound
// 1 2 3 4 5 5 5 6 7 9
//               ^-- upper bound
int upper_bound(int x, vector<int>a){ 
	int l = 0; int r = a.size() - 1;	
	int ans = a.size();
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] > x) { // candidate for answer
			ans = m;
			r = m - 1; // look on left for a smaller candidate 
		} else {
			l = m + 1;
		}
	}
	return ans;
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i <n ;i++){
		cin >> a[i];
	}
	int x; cin >> x;
	cout << upper_bound(x, a) << endl;
	return 0;
}

