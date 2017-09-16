/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        map<int, vector<int>>m;
        deque<pair<int, TreeNode*>>cur;
        deque<pair<int, TreeNode*>>next;
        cur.push_back(make_pair(0, root));
        while(!cur.empty()){
            auto p = cur.front();
            cur.pop_front();
            m[p.first].push_back(p.second->val);
            if(p.second->left) next.push_back(make_pair(p.first - 1, p.second->left));
            if(p.second->right) next.push_back(make_pair(p.first + 1, p.second->right));
            if(cur.empty()) swap(cur, next);
        }
        for(auto x: m) res.push_back(x.second);
        return res;
    }
};
