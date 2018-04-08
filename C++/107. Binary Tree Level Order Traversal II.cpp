class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        dfs(root, v, 0);
        reverse(v.begin(), v.end());
        return v;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& v, int level){
        if(!root) return;
        if(level == v.size()) v.push_back({});
        v[level].push_back(root->val);
        dfs(root->left, v, level + 1);
        dfs(root->right, v, level + 1);
    }
};
