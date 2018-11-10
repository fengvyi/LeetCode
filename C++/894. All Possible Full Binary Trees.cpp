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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (N == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }
        --N;
        for (int i = 1; i < N; i += 2) {
            auto left = allPossibleFBT(i);
            auto right = allPossibleFBT(N - i);
            for (TreeNode* l: left) {
                for (TreeNode* r: right) {
                    TreeNode* cur = new TreeNode(0);
                    cur->left = l;
                    cur->right = r;
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};
