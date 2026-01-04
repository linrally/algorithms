#include <iostream>
using namespace std;

long long maximumTotalDamage(vector<int>& power) {
	unordered_map<int,int> f;	
	for(int x: power){
		f[x]++;
	}
	vector<int> unique;
	for(pair<int,int> p: f){
		unique.push_back(p.first);
	}
	sort(unique.begin(), unique.end());
	int n = unique.size();
	vector<long long> dp(n + 1, 0);
	int j = 0; // j is the index of the largest power < val - 2
	for(int i = 1; i <= n; i++){
		long long val = unique[i-1];
		while(unique[j] < val - 2) j++; // monotonic pointer
		dp[i] = max(dp[i-1], dp[j] + val * f[val]);	
	}
	return dp[n];
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << maximumTotalDamage(v) << endl;
	return 0;
}
