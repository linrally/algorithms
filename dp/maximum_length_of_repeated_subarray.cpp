#include <iostream>
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 or j == 0) dp[i][j] = 0;
			else if (nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1; // extend current sequence
			else dp[i][j] = 0; // reset
		}
	}
	int res = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			res = max(res, dp[i][j]);
		}
	}
	return res;
}

int main() {
	int N; cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	int M; cin >> M;
	vector<int> B(M);
	for(int i = 0; i < M; i++) cin >> B[i];
	cout << findLength(A, B) << endl;
	return 0;
}
