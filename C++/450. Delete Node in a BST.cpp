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
        if (!root) {
            return NULL;
        }
        TreeNode* head = new TreeNode(0);
        head->left = root;
        TreeNode* parent;
        TreeNode* node = dfs(root, head, key, parent);
        if (!node) {
            return root;
        }
        
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        TreeNode* p = r;
        while (p && p->left) {
            p = p->left;
        }
        if (!r) {
            r = l;
        } else if (p) {
            p->left = l;
        }
        if (node == parent->left) {
            parent->left = r;
        } else {
            parent->right = r;
        }
        return head->left;
    }
    
    TreeNode* dfs(TreeNode* cur, TreeNode* pre, int key, TreeNode*& parent) {
        if (!cur) {
            return NULL;
        }
        if (cur->val == key) {
            parent = pre;
            return cur;
        }
        
        if (cur->val > key) {
            return dfs(cur->left, cur, key, parent);
        } else {
            return dfs(cur->right, cur, key, parent);
        }
    }
};
