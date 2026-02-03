#include <iostream>
using namespace std;

vector<int> plusOne(vector<int> a){
	vector<int> res = a;
	int i = a.size() - 1;	
	int carry = 1;
	while(i >= 0){
		if(res[i] + carry == 10){
			res[i] = 0;	
			carry = 1;
		} else {
			res[i] += carry;
			carry = 0;
		}
		i--;
	}
	if(carry == 1){ // trick because we are doing +1, set first to 1 and add 0 to back (ex. 99, 999, 9999)
		res[0] = 1;
		res.push_back(0);
	}
	return res;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	vector<int> r = plusOne(v);
	for(int x: r) cout << x << " ";
	cout << endl;
	return 0;
}
