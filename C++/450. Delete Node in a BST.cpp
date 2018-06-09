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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* head = new TreeNode(0);
        head->left = root;
        dfs(head, root, key);
        return head->left;
    }
    
    void dfs(TreeNode* pre, TreeNode* cur, int key){
        if(!cur) return;
        cur->val > key ? dfs(cur, cur->left, key) : cur->val < key ? dfs(cur, cur->right, key) : helper(pre, cur);
    }
    
    void helper(TreeNode* pre, TreeNode* cur){
        TreeNode* p = cur->left;
        while(p && p->right) p = p->right;
        p ? p->right = cur->right : cur->left = cur->right;
        cur == pre->left ? pre->left = cur->left : pre->right = cur->left;
    }
};
