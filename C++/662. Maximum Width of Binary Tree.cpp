// BFS
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxWidth = 1;
        deque<pair<TreeNode*, int>>cur;
        deque<pair<TreeNode*, int>>next;
        cur.push_back({root, 1});
        while(!cur.empty()){
            auto p = cur.front();
            cur.pop_front();
            if(p.first->left) next.push_back({p.first->left, p.second * 2});
            if(p.first->right) next.push_back({p.first->right, p.second * 2 + 1});
            if(cur.empty() && !next.empty()){
                swap(cur, next);
                maxWidth = max(maxWidth, cur.back().second - cur.front().second + 1);
            }
        }
        return maxWidth;
    }
};

// DFS
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        vector<int>v;
        DFS(root, v, 1, 0, maxWidth);
        return maxWidth;
    }
    
    void DFS(TreeNode* root, vector<int>& v, int tag, int level, int& maxWidth){
        if(!root) return;
        if(v.size() == level) v.push_back(tag);
        maxWidth = max(maxWidth, tag - v[level] + 1);
        DFS(root->left, v, tag * 2, level + 1, maxWidth);
        DFS(root->right, v, tag * 2 + 1, level + 1, maxWidth);
    }
};
