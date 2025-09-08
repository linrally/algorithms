#include <iostream>
#include <unordered_map>
using namespace std;
  
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int,int> m;
	for(int i = 0; i<nums.size(); i++){
		if(m.contains(nums[i])){
			return {i, m[nums[i]]};	
		}
		m[target - nums[i]] = i;
	}
	return {};
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i <n; i++){
		cin >> v[i];
	}
	int t; cin >> t;
	vector<int> res = twoSum(v, t);
	for(int x:res){
		cout << x << " ";
	}
	return 0;
}

