// DFS
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        dfs(root, res, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int& res, int num){
        num = num * 10 + root->val;
        if(root->left) dfs(root->left, res, num);
        if(root->right) dfs(root->right, res, num);
        if(!root->left && !root->right) res += num;
    }
};

// BFS
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int num = p.second * 10 + p.first->val;
            if(p.first->left) q.push({p.first->left, num});
            if(p.first->right) q.push({p.first->right, num});
            if(!p.first->left && !p.first->right) res += num;
        }
        return res;
    }
};
