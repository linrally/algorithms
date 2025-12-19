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
	
	// reconstruct
	// int i = n, j = B;
	// vector<Item> selected;
	// while(i > 0){
	// 	if(dp[i][j] == dp[i-1][j-items[i-1].weight] + items[i-1].price){
	// 		selected.push_back(items[i-1]);
	// 		j -= items[i-1].weight;
	// 	}
	// 	i--;
	// }
	// for(Item &it: selected) cout << it.price << " " << it.weight << endl;

	return dp[n][B];
}

int knapsack_2row(const vector<Item> &items, const int B){
	int n = items.size();
	vector<int> prev(B + 1);
	vector<int> cur(B + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j<= B; j++){
			if(j >= items[i-1].weight){
				cur[j] = max(prev[j], prev[j - items[i-1].weight] + items[i-1].price);
			} else {
				cur[j] = prev[j];
			}
		}
		prev = cur;
	}
	return cur[B];
}

int main() {
	int N; cin >> N;
	vector<Item> items(N);
	for(int i = 0; i < N; i++){
		cin >> items[i].price >> items[i].weight;
	}
	int B; cin >> B;
	cout << knapsack(items, B) << endl;
	// cout << knapsack_2row(items, B) << endl;
	return 0;
}
