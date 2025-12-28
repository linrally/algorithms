#include <iostream>
using namespace std;

int trap(vector<int> &height){
	int N = height.size();
	vector<int> tl(N), tr(N);
	for(int i = 1; i < N; i++){
		tl[i] = max(tl[i-1], height[i-1]);
	}
	for(int i = N - 2; i >= 0; i--){
		tr[i] = max(tr[i+1], height[i+1]);
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		int add = min(tl[i], tr[i]) - height[i];
		if(add > 0) ans += add;
	}
	return ans;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << trap(v) << endl;
	return 0;
}
