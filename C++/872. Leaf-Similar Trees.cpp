class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        int pos = 0;
        dfs(root1, v, pos);
        pos = 0;
        return dfs(root2, v, pos);
    }
    
    bool dfs(TreeNode* p, vector<int>& v, int& pos){
        if(!p) return true;
        if(!p->left && !p->right){
            if(v.size() == pos) v.push_back(p->val);
            return v[pos++] == p->val;
        }
        return dfs(p->left, v, pos) && dfs(p->right, v, pos);
    }
};
