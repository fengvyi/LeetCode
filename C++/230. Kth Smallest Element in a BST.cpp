/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Solution 1
class Solution {
public:
    int DFS(TreeNode* root, int k, int& val, bool& found){
       if(!root || found) return 0;
       int left = DFS(root->left, k, val, found) + 1;
       int right = DFS(root->right, k - left, val, found) + 1;
       if(k == left) val = root->val, found = true;
       return left + right - 1;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int val = 0;
        bool found = false;
        DFS(root, k, val, found);
        return val;
    }
};

// Solution 2
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<int>s;
        reversedInOrder(root, s);
        while(--k) s.pop();
        return s.top();
    }
    
    void reversedInOrder(TreeNode* root, stack<int>& s){
        if(!root) return;
        reversedInOrder(root->right, s);
        s.push(root->val);
        reversedInOrder(root->left, s);
    }
};
