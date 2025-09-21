#include <iostream>
using namespace std;

bool isValid(string s){
	int n = s.size();
	stack<char> st;
	for(int i = 0; i<n; i++){
		if(s[i] == '{' or s[i] == '[' or s[i] == '('){
			st.push(s[i]);
		} else {
			if (st.empty()) return false;
			char t = st.top(); st.pop();
			if(t == '{' and s[i] != '}') return false;
			if(t == '[' and s[i] != ']') return false;
			if(t == '(' and s[i] != ')') return false;
		}
	}
	if(not st.empty()) return false;
	return true;
}

int main() {
	string s; cin >> s;
	cout << isValid(s) << endl;
	return 0;
}
