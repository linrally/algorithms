#include <iostream>
using namespace std;

struct Interval{
	int s { };
	int f { };
	int w { };
};

bool comp(const Interval &a, const Interval &b){
	return a.f < b.f;
}

int largestWeightSubset(vector<Interval>& intervals){
	// DP[i] is the weight of best subset of the first i intervals 
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), &comp);

	vector<int> finish(n);
	for (int i = 0; i < n; i++)
			finish[i] = intervals[i].f;

	vector<int> sigma(n); // index of last non overlapping interval
	for(int i = 0; i < n; i++){
		vector<int>::iterator it = upper_bound(finish.begin(), finish.end(), intervals[i].s);
		sigma[i] = it - finish.begin() - 1;
	}

	vector<int> dp(n);
	dp[0] = intervals[0].w;
	for(int i = 1; i<n; i++){
		int include = intervals[i].w;
		if(sigma[i] != -1)
				include += dp[sigma[i]];
		int exclude = dp[i-1];
		dp[i] = max(include, exclude);
	}
	
	return dp[n-1];
}

int main() {
	int N; 
	cin >> N;
	vector<Interval> intervals;
	for(int i = 0; i < N; i++){
		Interval iv;
		cin >> iv.s >> iv.f >> iv.w;
		intervals.push_back(iv);
	}
	cout << largestWeightSubset(intervals) << endl;
	return 0;
}
