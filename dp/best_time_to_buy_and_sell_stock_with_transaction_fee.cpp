#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
	 int n = prices.size(); 
	 int hold = -prices[0]; // maximum profit while holding a stock
	 int sold = 0; // maximum profit while not holding a stock
	 for(int i = 1; i < n; i++){
		hold = max(hold, sold - prices[i]);
		sold = max(sold, hold + prices[i] - fee);
	 }
	 return sold;
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	int K; cin >> K;
	cout << maxProfit(v, K) << endl;
	return 0;
}
