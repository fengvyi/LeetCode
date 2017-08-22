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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int>m;
        return DFS(root, m, k);
    }
    
    bool DFS(TreeNode* root, unordered_map<int, int>& m, int k){
        if(!root) return false;
        if(m.count(k - root->val)) return true;
        m[root->val]++;
        return DFS(root->left, m, k) || DFS(root->right, m, k);
    }
};
