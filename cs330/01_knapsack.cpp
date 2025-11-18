#include <iostream>
using namespace std;

struct Item{
	int price {};
	int weight {};
};

int knapsack(const vector<Item> &items, const int B){
	int n = items.size();
	vector<vector<int>> dp(n + 1, vector<int>(B + 1, 0)); // 1 indexing items so dp[0] can represent no items
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= B; j++){
			Item cur = items[i-1];
			int exclude = dp[i-1][j];
			int include = (j >= cur.weight ? cur.price + dp[i-1][j - cur.weight] : 0);
			dp[i][j] = max(exclude, include);
		}
	}
	return dp[n][B];
}

int main() {
	int N; cin >> N;
	vector<Item> items(N);
	for(int i = 0; i < N; i++){
		cin >> items[i].price >> items[i].weight;
	}
	int B; cin >> B;
	cout << knapsack(items, B) << endl;
	return 0;
}
