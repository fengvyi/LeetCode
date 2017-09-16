/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // BST.
 class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* candidate = NULL;
        while(root){
            if(root->val > p->val){
                candidate = root;
                root = root->left;
            }
            else root = root->right;
        }
        return candidate;
    }
};

// Any Binary Tree.
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*>s;
        DFS(root, s);
        while(s.top() != p) s.pop();
        s.pop();
        return s.empty() ? NULL : s.top();
    }
    
    void DFS(TreeNode* root, stack<TreeNode*>& s){
        if(!root) return;
        DFS(root->right, s);
        s.push(root);
        DFS(root->left, s);
    }
};
