// DFS
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int maxlen = 0;
        DFS(NULL, root, 1, maxlen);
        return maxlen;
    }
    
    void DFS(TreeNode* from, TreeNode* cur, int len, int& maxlen){
        if(!cur) return;
        len = (from && cur->val == from->val + 1) ? len + 1 : 1;
        maxlen = max(maxlen, len);
        DFS(cur, cur->left, len, maxlen);
        DFS(cur, cur->right, len, maxlen);
    }
};

// BFS
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        deque<pair<TreeNode*, int>>q;
        q.push_back({root, 1});
        int maxlen = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop_front();
            if(p.first->left) q.push_back({p.first->left, (p.first->left->val == p.first->val + 1) ? p.second + 1 : 1});
            if(p.first->right) q.push_back({p.first->right, (p.first->right->val == p.first->val + 1) ? p.second + 1 : 1});
            maxlen = max(maxlen, p.second);
        }
        return maxlen;
    }
};
