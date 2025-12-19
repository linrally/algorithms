#include <iostream>
using namespace std;

struct Lecture{
	int chalkboard {};
	int blackboard {};
};

int maxLearning(const vector<Lecture>&lectures, const int K){
	int N = lectures.size();
	vector<vector<int>> dp(N, vector<int>(2));
	dp[0][0] = lectures[0].chalkboard;
	dp[0][1] = lectures[0].blackboard;
	for(int i = 1; i < N; i++){
		dp[i][0] = max(dp[i-1][0] + lectures[i].chalkboard, dp[i-1][1] + lectures[i].chalkboard - K);
		dp[i][1] = max(dp[i-1][1] + lectures[i].blackboard, dp[i-1][0] + lectures[i].blackboard - K);
	}
	return max(dp[N-1][0], dp[N-1][1]);
}

int main() {
	int N; cin >> N;
	vector<Lecture> lectures(N);
	for(int i = 0; i < N; i++){
		cin >> lectures[i].chalkboard >> lectures[i].blackboard;
	}
	int K; cin >> K; // switching cost
	cout << maxLearning(lectures, K) << endl;
	return 0;
}
