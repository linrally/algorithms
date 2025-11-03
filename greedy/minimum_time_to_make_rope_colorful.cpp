#include <iostream>
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
	 // If two consecutive are the same color, remove the minimum of the two (greedy)
	 int n = colors.size();
	 int cost = 0;
	 int i = 0;
	 while(i < n){
		int mx = 0;
		int sum = 0;
		int j = i;
		while(j < n and colors[i] == colors[j]){
				mx = max(neededTime[j], mx);
				sum += neededTime[j];
				j++;
		}
		cost += sum - mx;
		i = j;
	 }
	 return cost;
}

int main() {
	string s; cin >> s;
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << minCost(s, v) << endl;
	return 0;
}
