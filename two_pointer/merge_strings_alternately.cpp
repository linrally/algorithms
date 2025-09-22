#include <iostream>
using namespace std;

string mergeAlternately(string word1, string word2) {
	int i = 0, j = 0;
	string s = "";
	while(i < word1.size() and j < word2.size()){
			if(s.size() % 2 == 0){
					s += word1[i];
					i++;
			} else {
					s += word2[j];
					j++;
			}
	}
	if(i < word1.size()) s += word1.substr(i);
	if(j < word2.size()) s += word2.substr(j);
	return s;
}

int main() {
	return 0;
}
