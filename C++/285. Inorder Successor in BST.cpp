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
        bool found = false;
        helper(root, p, s, found);
        return found ? s.top() : NULL;
    }
    
    void helper(TreeNode* root, TreeNode* p, stack<TreeNode*>& s, bool& found){
        if(!root) return;
        helper(root->left, p, s, found);
        if(!s.empty() && s.top() == p){
            s.push(root);
            found = true;
            return;
        }
        if(found) return;
        s.push(root);
        helper(root->right, p, s, found);
    }
};
