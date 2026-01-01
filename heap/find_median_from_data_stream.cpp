#include <iostream>
using namespace std;

class MedianFinder {
public:
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;

	MedianFinder() { }
	
	void addNum(int num) {
		if(min_pq.empty() and max_pq.empty()){
			min_pq.push(num);
			return;
		}
		if(num > min_pq.top()) min_pq.push(num);
		else max_pq.push(num);
		if(max_pq.size() > min_pq.size() + 1){
			int temp = max_pq.top(); max_pq.pop();
			min_pq.push(temp);
		}
		if(min_pq.size() > max_pq.size() + 1){
			int temp = min_pq.top(); min_pq.pop();
			max_pq.push(temp);
		}
	}
	
	double findMedian() {
		if((max_pq.size() + min_pq.size()) % 2 == 0){
			return (max_pq.top() + min_pq.top()) / 2.0;
		}
		if(max_pq.size() > min_pq.size()) return max_pq.top();
		else return min_pq.top();
	}
};

int main() {
	MedianFinder medianFinder;
	medianFinder.addNum(1);    // arr = [1]
	medianFinder.addNum(2);    // arr = [1, 2]
	cout << medianFinder.findMedian() << endl; // return 1.5 (i.e., (1 + 2) / 2)
	medianFinder.addNum(3);    // arr[1, 2, 3]
	cout << medianFinder.findMedian() << endl; // return 2.0
	return 0;
}
