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
        if(s->val == t->val && isEqual(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
private:
    bool isEqual(TreeNode* p, TreeNode* t){
        if(!p || !t) return !p && !t;
        if(p->val != t->val) return false;
        return isEqual(p->left, t->left) && isEqual(p->right, t->right);
    }
};
