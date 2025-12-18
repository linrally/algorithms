#include <iostream>

template<typename T> class Stack{
	private:
		std::vector<T> vec;

	public:
		Stack () {}

		void push(T val){
			vec.push_back(val);
		}
		
		T pop(){
			T temp = vec[vec.size() - 1];	
			vec.pop_back();
			return temp;
		}

		bool empty(){
			return vec.empty();
		}
};

int main(){
	int x;
	Stack<int> s;
	while(std::cin >> x){
		s.push(x);
	}
	while(not s.empty()){
		std::cout << s.pop() << std::endl;
	}
	return 0;
}


