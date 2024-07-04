#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> imap;
		for (int i=0; i<inorder.size(); ++i) imap[inorder[i]] = i;

		return build(0, preorder.size()-1, 0, inorder.size()-1, preorder, imap);
    }

private:
	TreeNode* build(int pstart, int pend, int istart, int iend, vector<int>& preorder, unordered_map<int, int>& imap) {
		if ((pend < pstart) || (iend < istart)) return nullptr;

		int val = preorder[pstart];
		TreeNode *root = new TreeNode(val);
		
		int imid = imap[val];
		int left_len = imid - istart;

		root->left = build(pstart+1, pstart+left_len, istart, istart + left_len, preorder, imap);
		root->right = build(pstart+left_len+1, pend, imid+1, iend, preorder, imap);

		return root;
	}	
};
