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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return !t;
        return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isEqual(TreeNode* p, TreeNode* t){
        if(!p || !t) return !p && !t;
        return p->val == t->val && isEqual(p->left, t->left) && isEqual(p->right, t->right);
    }
};
