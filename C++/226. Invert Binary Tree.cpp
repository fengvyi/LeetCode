/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Solution 1. Recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

// Solution 2. Iterative
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* p = root;
        while(!s.empty() || p){
            while(p){
                s.push(p);
                p = p->left;
            }
            while(!s.empty() && !p){
                p = s.top()->right;
                swap(s.top()->left, s.top()->right);
                s.pop();
            }
        }
        return root;
    }
};
