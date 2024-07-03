#include <string>
#include <utility>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:

    string serialize(TreeNode* root) {
        string s;
		return encode(root, s);
    }

    TreeNode* deserialize(string& data) {
        cout << data << endl;
		return decode(0, data).first;
    }

private:
	string encode(TreeNode* root, string& stream) {
		if (root == nullptr) {
			stream.push_back('N');
			stream.push_back(',');
			return stream;
		}

		stream.append(to_string(root->val));
		stream.push_back(',');
		encode(root->left, stream);
		encode(root->right, stream);
		return stream;
	}

	pair<TreeNode*, int> decode(int i, string& data) {
		if (data[i] == 'N') {
			return pair<TreeNode*, int>(nullptr, i+2);
		}

        int j = i;
		while (data[j] != ',') ++j;
		TreeNode* root = new TreeNode(stoi(data.substr(i, j-i)));

        pair<TreeNode*, int> left = decode(j+1, data);
        pair<TreeNode*, int> right = decode(left.second, data);

        root->left = left.first;
        root->right = right.first;

		return pair<TreeNode*, int>(root, right.second);
	}
};
