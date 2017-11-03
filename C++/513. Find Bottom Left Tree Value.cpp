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
    int findBottomLeftValue(TreeNode* root) {
        int res = 0, maxLevel = -1;
        DFS(root, 0, maxLevel, res);
        return res;
    }
    
    void DFS(TreeNode* root, int level, int& maxLevel, int& res){
        if(!root) return;
        DFS(root->left, level + 1, maxLevel, res);
        DFS(root->right, level + 1, maxLevel, res);
        if(level > maxLevel) res = root->val;
        maxLevel = max(maxLevel, level);
    }
};
