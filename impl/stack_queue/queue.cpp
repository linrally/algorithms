#include <iostream>

template <typename T> struct Node{
	T val {};
	Node* next { nullptr };
};

template <typename T> class Queue{
	private:
		Node<T>* head { nullptr };
		Node<T>* tail { nullptr };

	public:
		Queue () {}

		void push (T val){
			if(tail == nullptr) {
				tail = new Node<T>(val, nullptr);
				head = tail;
			} else {
				tail->next = new Node<T>(val, nullptr);	
				tail = tail->next;
			}
		}

		T pop(){
			if(head == tail) tail = nullptr;
			T temp = head->val;
			head = head->next;
			return temp;
		}

		bool empty(){
			return head == nullptr and tail == nullptr;
		}
};

int main() {
		int x;
		Queue<int> s;
		while(std::cin >> x){
			s.push(x);
		}
		while(not s.empty()){
			std::cout << s.pop() << std::endl;
		}
		return 0;

}
