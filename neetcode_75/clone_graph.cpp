#include <iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*> mp;

Node* cloneGraph(Node* node) {
	if(not node) return nullptr;
	if(mp.count(node)) return mp[node];
	Node* res = new Node(node->val);
	mp[node] = res;
	for(Node* u: node->neighbors){
			res->neighbors.push_back(cloneGraph(u));
	}
	return res;
}

int main() {
	int N; 
	cin >> N;
	vector<vector<int>> edges(N, vector<int>(2));
	for(int i = 0; i < N; i++){
	    cin >> edges[i][0] >> edges[i][1];
	}
	// parse
	return 0;
}
