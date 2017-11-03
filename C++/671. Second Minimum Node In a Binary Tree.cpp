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
    int findSecondMinimumValue(TreeNode* root) {
        int res = INT_MAX;
        DFS(root, root->val, res);
        return res == INT_MAX ? -1 : res;
    }
    
    void DFS(TreeNode* root, int val, int& res){
        if(!root) return;
        if(root->val != val) res = min(res, root->val);
        if(root->val == val) DFS(root->left, val, res), DFS(root->right, val, res);
    }
};
