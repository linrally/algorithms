#include <iostream>
using namespace std;

static string lstrip(string s){
	int i = s.find_first_not_of("0");
	if(i == -1){
		if(s[0] == '0') return "0";
		return s;
	}
	return s.substr(i);
}

string removeKdigits(string num, int k) {
	if(num.size() == 1 and k >= 1) return "0";
	stack<char> st;	
	for(char c : num){
		while(not st.empty() and st.top() > c and k > 0){
			st.pop();
			k--;
		}
		st.push(c);
	}
	while(not st.empty() and k > 0){
		st.pop(); k--;
	}
	string res = "";
	if(st.empty()) return "0";
	while(not st.empty()){
		res += st.top(); st.pop();
	}
	reverse(res.begin(), res.end());
	return lstrip(res);
}

int main() {
	string s; cin >> s;
	int k; cin >> k;
	cout << removeKdigits(s, k) << endl;
	return 0;
}
