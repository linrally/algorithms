#include <iostream>
using namespace std;
// Slow solution that does not use hashing
// vector<vector<string>> groupAnagrams(vector<string>& strs) {
// 	vector<vector<int>> fmaps;
// 	vector<vector<string>> groups;
// 	for(int i = 0; i<strs.size(); i++){
// 		string s = strs[i];
// 		vector<int> f(26, 0);
// 		for(char c: s){
// 			f[c - 'a']++;
// 		}
// 		bool newf = true;
// 		for(int j = 0; j < fmaps.size(); j++){
// 			bool flag = true;
// 			for(int k = 0; k <fmaps[j].size(); k++){
// 				if(fmaps[j][k] != f[k]){
// 					flag = false;
// 					break;
// 				}
// 			}
// 			if(flag){
// 				groups[j].push_back(s);	
// 				newf = false;
// 				break;
// 			}
// 		}
// 		if(newf){
// 			fmaps.push_back(f);
// 			groups.push_back({s});
// 		}
// 	}
// 	return groups;
// }

// the fastest solution will define a hash or use sorted s as a key, but this works
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	map<vector<int>, vector<string>> mp; // map uses a BST on keys (O(logn) instead of O(1) complexity); default unordered_map cannot hash vector
	for(string s:strs){
		vector<int> f(26, 0);
		for(char c:s){
			f[c - 'a']++;
		}
		mp[f].push_back(s);
	}
	vector<vector<string>> res;
	for(auto &[f, group]: mp){
		res.push_back(group);
	}
	return res;
}	

int main() {
    return 0;
}
