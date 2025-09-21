#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	int bestPrice = INT_MAX;
	int maxProfit = 0;
	for(int i = 0; i<n; i++){
		bestPrice = min(prices[i], bestPrice);
		int profit = prices[i] - bestPrice;
		maxProfit = max(profit, maxProfit);	
	}
	return maxProfit;
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
