#include <iostream>
using namespace std;

int numberOfBeams(vector<string>& bank) {
	int n = bank.size();	
	int total = 0;
	int prev = 0, cur = 0;
	for(int i = 0; i < n; i++){
		cur = 0;
		for(int j = 0; j < bank[i].size(); j++){
			if(bank[i][j] == '1') cur++;
		}
		if(cur == 0) continue; 
		total += (cur * prev);
		prev = cur;
	}
	return total;
}

int main() {
	int N; cin >> N;
	vector<string> bank;
	for(int i = 0; i < N; i++){
		string s; cin >> s;
		bank.push_back(s);
	}
	cout << numberOfBeams(bank) << endl;
	return 0;
}
