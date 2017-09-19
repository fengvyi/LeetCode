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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        if(!root) return res;
        deque<TreeNode*>cur;
        deque<TreeNode*>next;
        cur.push_back(root);
        double sum = 0;
        int n = 0;
        while(!cur.empty()){
            TreeNode* p = cur.front();
            cur.pop_front();
            sum += p->val;
            n++;
            if(p->left) next.push_back(p->left);
            if(p->right) next.push_back(p->right);
            if(cur.empty()){
                res.push_back(sum / n);
                swap(cur, next);
                sum = n = 0;
            }
        }
        return res;
    }
};
