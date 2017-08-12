/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Both recursive / iterative solutions are included.
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        /** 
         * Recursive.
         * inorder(res, root);
         * return res;
         */
        if(!root) return res;
        stack<TreeNode*>s;
        TreeNode* cur = root;
        while(!s.empty() || cur){
            while(cur->left){
                s.push(cur);
                cur = cur->left;
            }
            res.push_back(cur->val);
            cur = cur->right ? cur->right : NULL;
            while(!cur && !s.empty()){
                res.push_back(s.top()->val);
                cur = s.top()->right ? s.top()->right : NULL;
                s.pop();
            }
        }
        return res;
    }
    
    void inorder(vector<int>& res, TreeNode* root){
        if(!root) return;
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
};
