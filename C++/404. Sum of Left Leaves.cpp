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
    int sumOfLeftLeaves(TreeNode* root) {
        return !root ? 0 : (root->left && !root->left->left && !root->left->right ? root->left->val : 0) + 
                           sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

// Iterative
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode*>s;
        int sum = 0;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root = root->left;
                if(root && !root->left && !root->right) sum += root->val;
            }
            root = s.top()->right;
            s.pop();
        }
        return sum;
    }
};
