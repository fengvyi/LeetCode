/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Solution 1. O(n) space.
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        load(s, root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        int n = s.top();
        s.pop();
        return n;
    }
    
private:
    stack<int>s;
    
    void load(stack<int>& s, TreeNode* root){
        if(!root) return;
        load(s, root->right);
        s.push(root->val);
        load(s, root->left);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
// Solution 2. O(h) space.
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        load(s, root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if(node->right) load(s, node->right);
        return node->val;
    }
    
private:
    stack<TreeNode*>s;
    
    void load(stack<TreeNode*>& s, TreeNode* root){
        if(!root) return;
        s.push(root);
        load(s, root->left);
    }
};
