#include <iostream>
using namespace std;

template <typename T> class StackFromQueue{
	private:
		queue<T> buf;

	public:
		T pop(){
			queue<T> temp;
			while(buf.size() > 1){
				temp.push(buf.front());
				buf.pop();
			}
			T x = buf.front(); buf.pop();
			buf = temp;
			return x;
		}

		void push(T val){
			buf.push(val);
		}

		bool empty(){
			return buf.empty();
		}
};

int main() {
	StackFromQueue<int> sfq;	
	sfq.push(1);
	sfq.push(2);
	sfq.push(3);
	while(not sfq.empty()){
		std::cout << sfq.pop() << std::endl;
	}
	return 0;
}
