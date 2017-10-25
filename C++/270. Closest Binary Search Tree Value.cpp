class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double minDiff = abs(root->val - target);
        int res = root->val;
        DFS(root, target, res, minDiff);
        return res;
    }
    
    void DFS(TreeNode* root, double target, int& res, double& minDiff){
        if(!root) return;
        if(abs(root->val - target) < minDiff) minDiff = abs(root->val - target), res = root->val;
        target > root->val ? DFS(root->right, target, res, minDiff) : DFS(root->left, target, res, minDiff);
    }
};
