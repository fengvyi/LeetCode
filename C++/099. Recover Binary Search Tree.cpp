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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL, *one = NULL, *two = NULL;
        DFS(root, pre, one, two);
        swap(one->val, two->val);
    }
    
    void DFS(TreeNode* cur, TreeNode* &pre, TreeNode* &one, TreeNode* &two){
        if(!cur) return;
        DFS(cur->left, pre, one, two);
        if(pre && cur->val < pre->val){
            if(!one) one = pre;
            two = cur;
        }
        pre = cur;
        DFS(cur->right, pre, one, two);
    }
};
