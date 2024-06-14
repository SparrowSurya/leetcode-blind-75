#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*<();
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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> hashmap;
        return clone(node, hashmap);
    }

    Node* clone(Node* node, unordered_map<int, Node*> hashmap) {
        if (node == NULL) return NULL;

        Node* copy = new Node(node->val);
        hashmap[node->val] = copy;

        for (Node* neighbor: node->neighbors) {
            if (hashmap.count(neighbor->val) == 0) {
                clone(neighbor, hashmap);
            }
            copy->neighbors.push_back(hashmap[neighbor->val]);
        }

        return copy;
    }
};
