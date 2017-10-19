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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        deque<TreeNode*>cur, next;
        cur.push_back(root);
        vector<int>v;
        int level = 0;
        while(!cur.empty()){
            auto p = cur.front();
            cur.pop_front();
            v.push_back(p->val);
            if(p->left) next.push_back(p->left);
            if(p->right) next.push_back(p->right);
            if(cur.empty()){
                if(level++ % 2) reverse(v.begin(), v.end());
                res.push_back(v);
                v.clear();
                swap(cur, next);
            }
        }
        return res;
    }
};
