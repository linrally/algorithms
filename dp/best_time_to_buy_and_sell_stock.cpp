#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
	int buy = INT_MAX;
	int profit = 0;
	for(int x: prices){
		buy = min(buy, x);
		profit = max(profit, x - buy);
	}
	return profit;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	cout << maxProfit(v) << endl;
	return 0;
}
