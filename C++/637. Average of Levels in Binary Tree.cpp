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
        deque<TreeNode*>sub;
        cur.push_back(root);
        double sum = 0;
        int count = 0;
        while(!cur.empty()){
            TreeNode* node = cur.front();
            cur.pop_front();
            if(node->left) sub.push_back(node->left);
            if(node->right) sub.push_back(node->right);
            sum += node->val;
            count++;
            if(cur.empty()){
                res.push_back(sum / count);
                sum = 0;
                count = 0;
                swap(cur, sub);
            }
        }
        return res;
    }
};
