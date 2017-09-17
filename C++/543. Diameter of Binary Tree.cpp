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
        int maxLen = 0;
        DFS(root, maxLen);
        return maxLen;
    }

private:
    int DFS(TreeNode* root, int& maxLen){
        if(!root) return 0;
        int left = DFS(root->left, maxLen);
        int right = DFS(root->right, maxLen);
        maxLen = max(maxLen, left + right);
        return max(left, right) + 1;
    }
};
