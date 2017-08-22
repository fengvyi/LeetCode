class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        DFS(root, sum);
        return root;
    }
    
    void DFS(TreeNode* root, int& sum){
        if(!root) return;
        DFS(root->right, sum);
        sum = (root->val += sum);
        DFS(root->left, sum);
    }
};
