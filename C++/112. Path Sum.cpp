class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        sum -= root->val;
        if(!sum && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
