/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// Solution 1. Brute force, T(n) = T(n/2) + O(n); Time complexity : O(n)
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
		bool foundP = found(root->left, p);
		bool foundQ = found(root->right, q);
		if (foundP && foundQ || !foundP && !foundQ) return root;
		if (foundP) return lowestCommonAncestor(root->left, p, q);
		return lowestCommonAncestor(root->right, p, q);
	}

	bool found(TreeNode* root, TreeNode* target) {
		if (!root) return false;
		if (root == target) return true;
		return found(root->left, target) || found(root->right, target);
	}
};

// Solution 2. T(n) = 2T(n/2), Time complexity: O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return left ? right ? root : left : right;
    }
};
