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
    int rangeSumBST(TreeNode* root, int L, int R) {
        return !root ? 0 : 
               root->val < L ? rangeSumBST(root->right, L, R) : 
               root->val > R ? rangeSumBST(root->left, L, R) : root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R);
    }
};
