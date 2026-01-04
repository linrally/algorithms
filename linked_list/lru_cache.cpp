#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
	int key;
	Node* next {nullptr};
	Node* prev {nullptr};
};

class LRUCache {
private:
	int capacity {};
	unordered_map<int, pair<int, Node*>> store;
	Node* front {nullptr};
	Node* back {nullptr};

	void update(Node* priority){ // moves node to the back of the LL
		if (priority == back) return;	
		else if (priority == front){
			front = front->next;
			if (front) front->prev = nullptr; // if (front) because if the list is size 1
		}
		else {
			priority->prev->next = priority->next;
			priority->next->prev = priority->prev;
		}
		priority->prev = back;
		priority->next = nullptr;
		if (back) back->next = priority;
		back = priority;
	}

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	
	int get(int key) {
		if(not store.contains(key)) return -1;
		pair<int, Node*>& entry = store[key];
		update(entry.second);
		return entry.first;
	}
	
	void put(int key, int value) {
		if(not store.contains(key) and store.size() == capacity){ // evict
			Node* victim = front;
			store.erase(victim->key);
			front = victim->next;
			if (front) front->prev = nullptr;
			else back = nullptr;
			delete victim;
		}
		Node* cur;
		if(not store.contains(key)){
			cur = new Node{key, nullptr, nullptr};
			if(front == nullptr){ // empty
				front = cur; 
			} else {
				back->next = cur;
				cur->prev = back;
			}
			back = cur;
		} else {
			cur = store[key].second;
			update(cur);
		}
		store[key] = {value, cur};
	}
};

int main() {
	LRUCache lRUCache {2};
	lRUCache.put(1, 1); // cache is {1=1}
	lRUCache.put(2, 2); // cache is {1=1, 2=2}
	cout << lRUCache.get(1) << endl;    // return 1
	lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	cout << lRUCache.get(2) << endl;    // returns -1 (not found)
	lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	cout << lRUCache.get(1) << endl;    // return -1 (not found)
	cout << lRUCache.get(3) << endl;    // return 3
	cout << lRUCache.get(4) << endl;    // return 4
	return 0;
}
