#include <utility>
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
    int maxPathSum(TreeNode* root) {
		pair<int, int> path_sum = find_path_sum(root);
		return max(path_sum.first, path_sum.second);
    }

	pair<int, int> find_path_sum(TreeNode* node) {
		if (node == nullptr) return pair<int, int>(0, INT_MIN);

		pair<int, int> left = find_path_sum(node->left);
		pair<int, int> right = find_path_sum(node->right);

		left.first = max(left.first, 0);
		right.first = max(right.first, 0);

		int sum_with_split = max(
			node->val + left.second + right.second,
			max(node->val, max(left.second, right.second))
		);

		int sum_without_split = node->val + max(left.first, right.first);

		return pair<int, int>(sum_without_split, sum_with_split);
	}
};
