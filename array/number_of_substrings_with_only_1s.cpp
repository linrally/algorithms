#include <iostream>
using namespace std;

const int P = 1e9 + 7;

int numSub(string s) {
		// loop through string with sliding window and count 1s 
		int n = s.size();
		int count = 0;
		int l = 0, r = 0;
		while(true){
			l = s.find('1', r);	
			if(l == -1) break;

			r = s.find('0', l);
			if(r == -1) r = n;

			int w = r - l;
			count += w * (w + 1) % P / 2;
		}
		return count;
}

int main() {
	string s; cin >> s;
	cout << numSub(s) << endl;
	return 0;
}
