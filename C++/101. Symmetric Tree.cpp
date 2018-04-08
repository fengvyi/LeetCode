// Recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<vector<TreeNode*>>v;
        dfs(root, v, 0);
        return check(v);
    }
    
    void dfs(TreeNode* root, vector<vector<TreeNode*>>& v, int level){
        if(level == v.size()) v.push_back({});
        v[level].push_back(root);
        if(!root) return;
        dfs(root->left, v, level + 1);
        dfs(root->right, v, level + 1);
    }
    
    bool check(vector<vector<TreeNode*>>& v){
        for(auto x: v){
            int l = 0, r = x.size() - 1;
            while(l < r){
                auto a = x[l++];
                auto b = x[r--];
                if((!a || !b) && (a || b) || (a && b) && (a->val != b->val)) return false;
            }
        }
        return true;
    }
};

// Iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<vector<TreeNode*>>v;
        queue<TreeNode*>cur, next;
        cur.push(root);
        int level = 0;
        while(!cur.empty()){
            auto p = cur.front();
            cur.pop();
            if(v.size() == level) v.push_back({});
            v[level].push_back(p);
            if(p){
                next.push(p->left);
                next.push(p->right);
            }
            if(cur.empty()){
                level++;
                swap(cur, next);
            }
        }
        return check(v);
    }
    
    bool check(vector<vector<TreeNode*>>& v){
        for(auto x: v){
            int l = 0, r = x.size() - 1;
            while(l < r){
                auto a = x[l++];
                auto b = x[r--];
                if((!a || !b) && (a || b) || (a && b) && (a->val != b->val)) return false;
            }
        }
        return true;
    }
};
