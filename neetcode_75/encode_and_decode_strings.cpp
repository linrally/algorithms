#include <iostream>
using namespace std;

vector<string> split(string s, string delimiter){
	int start = 0;
	int end = s.find(delimiter);
	vector<string> res;
	while(end != string::npos){
		string word = s.substr(start, end - start);
		res.push_back(word);
		start = end + delimiter.size();
		end = s.find(delimiter, start);
	}
	return res;
}

// string can have spaces or other special characters
// design a unique separator that is complex enough (but this is not completely generalizable)
// store a map of word lengths; can guarantee stored in prefix b/c we can set the first "$" and search for it
// the editorial has a chunked delimiter method (5/:Hello7:/32World7:/Example), but I think this can also be confused if the string has 5:/ in it
string encode(vector<string> &strs){
	string encoded = "";	
	for(string s: strs){
		encoded += to_string(s.size()) + "|";
	}
	encoded += "$";
	for(string s: strs){
		encoded += s;
	}
	return encoded;
}

vector<string> decode(string s){
	int idx = s.find("$");
	string pre = s.substr(0, idx);
	vector<string> raw = split(pre, "|");
	vector<int> sizes;
	for(string sz: raw){
		sizes.push_back(stoi(sz));
	}
	vector<string> res;
	int start = idx + 1;
	for(int sz: sizes){
		string temp = s.substr(start,sz);	
		res.push_back(temp);
		start += sz;
	}
	return res;
}

int main() {
	int N; cin >> N;
	vector<string> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	string s = encode(v);
	vector<string> t = decode(s);
	for(string x: t){
		cout << x << " ";
	}
}
