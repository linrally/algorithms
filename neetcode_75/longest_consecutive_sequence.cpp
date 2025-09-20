#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums){
	unordered_set<int> s;
	for(int x: nums){
		s.insert(x);
	}
	int longest = 0;
	for(int x: s){ // if we iterate over nums here we will TLE because of duplicates
		if (!s.contains(x - 1)) {
			int c = x;
			int streak = 1;
			while(s.contains(c + 1)){
				c++;
				streak++;
			}
			longest = max(longest, streak);
		}
	}
	return longest;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << longestConsecutive(v) << endl;
	return 0;
}
