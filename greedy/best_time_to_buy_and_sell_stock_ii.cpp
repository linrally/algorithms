#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int profit = 0;
		for(int i = 1; i < n; i++){
			 if(prices[i] > prices[i-1]){
				profit += prices[i] - prices[i-1];
			 }
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
