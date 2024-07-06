using namespace std;

#define Index(ch) (ch - 'a')

struct TrieNode {
	TrieNode *children[26];
	bool isEnd;

	TrieNode() {
		isEnd = false;
		for (auto &c: children) c = nullptr;
	}

	TrieNode *get_or_create(char ch) {
		int i = Index(ch);
		if (children[i] != nullptr) {
			return children[i];
		}
		TrieNode *node = new TrieNode();
		children[i] = node;
		return node;
	}

	TrieNode *get(char ch) {
		return children[Index(ch)];
	}
};

class Trie {
	TrieNode *root;
public:
    Trie() {
		root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;
		for (char ch: word) {
			node = node->get_or_create(ch);
		}
		node->isEnd = true;
    }

    bool search(string word) {
        TrieNode *node = root;
		for (char ch: word) {
			node = node->get(ch);
			if (node == nullptr) return false;
		}
		return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
		for (char ch: prefix) {
			node = node->get(ch);
			if (node == nullptr) return false;
		}
		return true;
    }
};
