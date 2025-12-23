#include <iostream>

template <std::totally_ordered T>
class MonotonicStack {
	private:
		std::stack<T> st;

	public:
		void push(T val){ // T must be a comparable type
			while(!st.empty() and st.top() < val) st.pop();
			st.push(val);
		}

		T pop(){
			T temp = st.top();
			st.pop();
			return temp;
		}

		bool empty(){
			return st.empty();
		}
};

int main(){
	MonotonicStack<int> st;
	st.push(5);
	st.push(3);
	st.push(4);
	st.push(2);
	while(not st.empty()){
		std::cout << st.pop() << std::endl;
	}
	return 0;
}
