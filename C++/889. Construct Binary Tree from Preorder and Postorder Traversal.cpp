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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[0]);
        
        if(pre.size() == 1) {
            return root;
        }
        
        vector<int>preLeft, preRight, postLeft, postRight;
        int rootLeft = pre[1];
        int pos = find(post.begin(), post.end(), rootLeft) - post.begin();
        
        postLeft.assign(post.begin(), post.begin() + pos + 1);
        postRight.assign(post.begin() + pos + 1, post.end() - 1);
        preLeft.assign(pre.begin() + 1, pre.begin() + 1 + pos + 1);
        preRight.assign(pre.begin() + 1 + pos + 1, pre.end());
        
        root->left = constructFromPrePost(preLeft, postLeft);
        root->right = constructFromPrePost(preRight, postRight);
        
        return root;
    }
};
