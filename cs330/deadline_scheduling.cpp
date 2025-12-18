#include <iostream>
using namespace std;

struct Job {
	int deadline {};
	int profit {};
};

bool comp(Job j1, Job j2){
	if(j1.profit == j2.profit){
		return j1.deadline > j2.deadline;
	}
	return j1.profit > j2.profit;
}

// greedy - schedule each job at the latest time it can be scheduled, starting with highest profit
int maxProfit(vector<Job> v){
	sort(v.begin(), v.end(), comp);	
	int maxDeadline = 0;
	for(Job &j: v){
		maxDeadline = max(maxDeadline, j.deadline);	
	}
	vector<bool> scheduled(maxDeadline);
	int profit = 0;
	for(Job &j:v){
		int i = j.deadline - 1;
		while(i > 0 and scheduled[i]) i--;
		if(scheduled[i]) continue; // no space
		scheduled[i] = true;
		profit += j.profit;
	}
	return profit;
}

int main() {
	int N; 
	cin >> N;
	vector<Job> v(N);
	for(int i = 0; i < N; i++){
		cin >> v[i].deadline >> v[i].profit;
	}
	cout << maxProfit(v) << endl;
	return 0;
}
