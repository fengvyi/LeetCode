// BFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int>res;
        deque<TreeNode*>cur, next;
        cur.push_back(root);
        int val = INT_MIN;
        while(!cur.empty()){
            auto p = cur.front();
            cur.pop_front();
            if(p->left) next.push_back(p->left);
            if(p->right) next.push_back(p->right);
            val = max(val, p->val);
            if(cur.empty()){
                swap(cur, next);
                res.push_back(val);
                val = INT_MIN;
            }
        }
        return res;
    }
};

// DFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        DFS(root, res, 0);
        return res;
    }
    
    void DFS(TreeNode* root, vector<int>& res, int level){
        if(!root) return;
        if(res.size() == level) res.push_back(root->val);
        res[level] = max(res[level], root->val);
        DFS(root->left, res, level + 1);
        DFS(root->right, res, level + 1);
    }
};
