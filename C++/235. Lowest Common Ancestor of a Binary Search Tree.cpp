/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int Min = min(p->val, q->val);
        int Max = max(p->val, q->val);
        if(root->val <= Max && root->val >= Min) return root;
        if(root->val > Max) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};
