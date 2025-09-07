
#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
	int f1[26]{}, f2[26]{};        
	for(int i = 0; i<s.size(); i++){
		f1[s[i] - 'a']++;	
	}
	for(int i = 0; i<t.size(); i++){
		f2[t[i] - 'a']++;	
	}
	for(int i = 0; i<26; i++){
		if (f1[i] != f2[i]) return false;
	}
	return true;
}

int main(){
	string s, t; cin >> s >> t;
	cout << isAnagram(s,t) << endl;
	return 0;
}

