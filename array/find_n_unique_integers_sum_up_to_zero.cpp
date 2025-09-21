#include <iostream>
using namespace std;


vector<int> sumZero(int n) {
	vector<int> res;
	if(n % 2 != 0){
        res.push_back(0); n--;
    } 
	for(int i = 1; i <= n/2; i++){
		res.push_back(i);
		res.push_back(-1*i);
	}	
	return res;
}

int main() {
	int N; cin >> N;
	vector<int> v = sumZero(N);
	for(int x:v){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
