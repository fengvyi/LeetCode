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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    vector<int> dfs(TreeNode* root, int& res){
        if(!root) return {INT_MAX, INT_MIN, 0};
        auto l = dfs(root->left, res);
        auto r = dfs(root->right, res);
        int count = (l[2] == -1 || r[2] == -1 || l[1] >= root->val || r[0] <= root->val) ? -1 : l[2] + r[2] + 1;
        res = max(res, count);
        return {min(root->val, min(l[0], r[0])), max(root->val, max(l[1], r[1])), count};
    }
};
