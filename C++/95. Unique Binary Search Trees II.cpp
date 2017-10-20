class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return DFS(1, n);
    }
    
    vector<TreeNode*> DFS(int l, int r){
        vector<TreeNode*>res;
        if(l > r) return {NULL};
        for(int i = l; i <= r; i++){
            auto left = DFS(l, i - 1);
            auto right = DFS(i + 1, r);
            for(auto x: left)
                for(auto y: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }    
        }
        return res;
    }
};
