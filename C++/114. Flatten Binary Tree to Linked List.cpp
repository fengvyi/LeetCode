/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* l, *r;
        DFS(root, l, r);
    }
    
    TreeNode* DFS(TreeNode* root, TreeNode* l, TreeNode* r){
        if(!root) return NULL;
        l = DFS(root->left, l, r);
        if(l){
            l->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        r = DFS(root->right, l, r);
        return r ? r : l ? l : root;
    }
};

// Iterative
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* p;
        while(root){
            if(root->left && root->right){
                p = root->left;
                while(p->right) p = p->right;
                p->right = root->right;
            }
            if(root->left) root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
};
