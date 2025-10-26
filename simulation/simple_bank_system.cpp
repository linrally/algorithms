#include <iostream>
using namespace std;

class Bank{
	public:
		vector<long long> balance;

		Bank(vector<long long>& balance) {
			this->balance = balance;							
		}
		
		bool transfer(int account1, int account2, long long money) {
			if(account1 <= 0 or account1 > balance.size()) return false;
			if(account2 <= 0 or account2 > balance.size()) return false;
			if(balance[account1 - 1] < money){
				return false;
			}
			balance[account1-1] -= money;
			balance[account2-1] += money;
			return true;
		}
		
		bool deposit(int account, long long money) {
			if(account <= 0 or account > balance.size()) return false;
			balance[account-1] += money;
			return true;
		}
		
		bool withdraw(int account, long long money) {
			if(account <= 0 or account > balance.size()) return false;
			if(balance[account - 1] < money){
				return false;
			}
			balance[account - 1] -= money;
			return true;
		}
};

int main() {
	vector<long long> balance = {10, 100, 20, 50, 30};
	Bank* obj = new Bank(balance);
	cout << obj->withdraw(3, 10) << endl;
	cout << obj->transfer(5, 1, 20) << endl;
	cout << obj->deposit(5, 20) << endl;
	cout << obj->transfer(3, 4, 15) << endl;
	cout << obj->withdraw(10, 50) << endl;
	return 0;
}
