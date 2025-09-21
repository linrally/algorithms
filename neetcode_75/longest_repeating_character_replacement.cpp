#include <iostream>
using namespace std;

int maxF(vector<int> f){
		int mx = 0;
		for(int x:f){
				mx = max(x, mx);
		}
		return mx;
}

// there is a faster way without needing to O(26)
int characterReplacement(string s, int k) {
		int n = s.size();
		vector<int> f(26);
		int l = 0, r = 0;
		int mfq = 0;
		int mx = 0;
		while (r < n){
				f[s[r] - 'A']++;
				mfq = maxF(f);
				while((r - l + 1) - mfq > k){
						f[s[l] - 'A']--;
						l++;
						mfq = maxF(f);
				}
				mx = max(mx, r - l + 1);
				r++;
		}
		return mx;
}

int main() {
	return 0;
}
