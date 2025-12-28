#include <iostream>
using namespace std;

int trap(vector<int>& height) {
	int N = height.size();
	stack<int> st;
	int ans = 0;
	for(int i = 0; i < N; i++){
			while(not st.empty() and height[i] > height[st.top()]){
					int top = st.top();
					st.pop();
					if(st.empty()) break;
					int w = i - st.top() - 1;
					int h = min(height[i], height[st.top()]) - height[top];
					ans += w * h;
			}        
			st.push(i);
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
