#include <iostream>
#include <unordered_set>
using namespace std;

// sliding window
// once we encounter a duplicate character, l++, r++
int lengthOfLongestSubstring(string s) {
	int n = s.size();
	int l = 0, r = 0;	
	int mx = 0;
	unordered_map<char,int> last;
	while(r < n){
		if(last.contains(s[r]) and last[s[r]] >= l){
			l = last[s[r]] + 1;
		}
		last[s[r]] = r;
		mx = max(mx, r-l+1);
		r++;
	}
	return mx;
}

int main() {
	string s; 
	getline(cin, s); // does not stop at whitespace
	cout << lengthOfLongestSubstring(s) << endl;
	return 0;
}
