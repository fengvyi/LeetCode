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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(!root) return res;
        DFS(root, res, "");
        return res;
    }
    
private:
    void DFS(TreeNode* root, vector<string>& res, string path){
        path += to_string(root->val);
        if(root->left || root->right) path += "->";
        else{
            res.push_back(path);
            return;
        }
        if(root->left) DFS(root->left, res, path);
        if(root->right) DFS(root->right, res, path);
    }
};
