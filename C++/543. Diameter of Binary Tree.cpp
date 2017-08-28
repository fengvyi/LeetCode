class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        return max(left + right, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    
    int DFS(TreeNode* root){
        if(!root) return 0;
        return 1 + max(DFS(root->left), DFS(root->right));
    }
};

// Update(08/28/2017):
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root);
        return maxPath;
    }

private:
    int maxPath = 0;
    
    int DFS(TreeNode* root){
        if(!root) return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        maxPath = max(maxPath, left + right);
        return 1 + max(left, right);
    }
};
