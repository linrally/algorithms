#include <iostream>
using namespace std;

// l = 0, n = n-1
// the width only decreases as we move closer together
// move the lower pillar inward
int maxArea(vector<int> &height){
	int n = height.size();
	int l = 0, r = n - 1;
	int mxArea = 0;
	while(l < r){
		int area = min(height[l], height[r]) * (r - l);
		mxArea = max(area, mxArea);
		if(height[l] > height[r]){
			r--;
		} else {
			l++;
		}
	}
	return mxArea;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << maxArea(v) << endl;
	return 0;
}
