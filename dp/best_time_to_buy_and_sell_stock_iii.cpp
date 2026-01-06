#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size();	
	vector<int> lprofit(n), rprofit(n);
	int buy = prices[0];
	for(int i = 1; i < n; i++){
		lprofit[i] = max(lprofit[i-1], prices[i] - buy);
		buy = min(buy, prices[i]);
	}
	int sell = prices[n-1];
	for(int i = n-2; i >=0; i--){
		rprofit[i] = max(rprofit[i+1], sell - prices[i]);
		sell = max(sell, prices[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
        int total = lprofit[i];
        if(i < n - 1) total += rprofit[i+1];
		ans = max(ans, total);
	}
	return ans;
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
