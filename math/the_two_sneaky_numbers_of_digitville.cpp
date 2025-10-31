#include <iostream>
using namespace std;

vector<int> quadratic(int a, int b, int c){
		double disc = b*b - 4*a*c;
		if (disc < 0) return {};
		int t1 = (-1*b + sqrt(disc))/(2*a);
		int t2 = (-1*b - sqrt(disc))/(2*a);
		return {t1, t2};
}

vector<int> getSneakyNumbers(vector<int>& nums) {
		// 1 + 2 +  ... + n + x + y= n(n+1)/2 + x + y
		// 1^2 + 2^2 + ... + n^2 + x^2 + y^2 = n(n+1)(2n+1)/6 + x^2 + y^2
		// we can find x + y = S and x^2 + y^2 = P
		// (x + y)^2 = x^2 + 2xy + y^2
		// xy = (S^2 - P)/2
		// we can represent the two solutions as a constructed quadratic with (t-x)(t-y) = 0
		// t^2 - (x + y)t + xy = 0
		// t^2 - St + (S^2 - P)/2 = 0
		int n = nums.size();
		int sum = 0;
		int sumsq = 0;
		for(int x: nums){
				sum += x;
				sumsq += x * x;
		}
		n = n - 3;
		int expectedSum = n * (n + 1) / 2;
		int expectedSumSq = n * (n + 1) * (2 * n + 1) / 6;
		int S = sum - expectedSum;
		int P = sumsq - expectedSumSq;
		return quadratic(1, -1*S, (S*S - P)/2);
}

int main() {
	int N; cin >> N;
	vector<int> v(N);
	for(int i = 0; i<N; i++){
		cin >> v[i];
	}
	vector<int> res = getSneakyNumbers(v);
	for(int x:res){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
