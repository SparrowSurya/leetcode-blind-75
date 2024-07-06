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

class WordDictionary {
	TrieNode *root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node = root;
		for (char ch: word) {
			node = node->get_or_create(ch);
		}
		node->isEnd = true;
    }
    
    bool search(string word) {
		return _search(root, word, 0);        
    }

private:
	bool _search(TrieNode *node, string word, int i) {
		if (i >= word.size()) return (node == nullptr || node->isEnd);

		if (word[i] == '.') {
			for (int j=0; j<26; ++j) {
				TrieNode *child = node->children[j];
				if (child == nullptr) continue;
				if (_search(child, word, i+1)) return true;
			}
			return false;
		}

		node = node->get(word[i]);
		return (node == nullptr)? false: _search(node, word, i+1);
	}
};
