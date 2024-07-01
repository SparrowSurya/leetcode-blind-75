using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return nullptr;

		auto new_left = invertTree(root->right);
		auto new_right = invertTree(root->left);
		root->left = new_left;
		root->right = new_right;
		return root;
    }
};
