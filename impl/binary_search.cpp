#include <iostream>
using namespace std;

int binary_search(int x, vector<int>a){
	int l = 0; int r = a.size() - 1 ;	
	while (l <= r){
		int m = (l + r) / 2;
		if (x == a[m]) return m;
		else if (x > a[m]) l = m + 1;
		else r = m - 1;
	}
	return -1;
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i <n ;i++){
		cin >> a[i];
	}
	int x; cin >> x;
	cout << binary_search(x, a) << endl;
	return 0;
}
