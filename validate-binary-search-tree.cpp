#include <limits>

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
	bool isValidBST(TreeNode *root) {
		return isValid(root, INT_MIN, INT_MAX);
	}

private:
	bool isValid(TreeNode *node) {
		if (node == nullptr) return true;
		if (node->val > right || left > node->val) return false;

		return isValid(node->left, left, node->val) && isValid(node->right, node->val, right);
	}	
};
