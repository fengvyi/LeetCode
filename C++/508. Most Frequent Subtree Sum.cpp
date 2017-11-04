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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>res;
        unordered_map<int, int>m;
        DFS(root, m);
        int maxFreq = 0;
        for(auto x: m)
            if(x.second > maxFreq) res.clear(), res.push_back(x.first), maxFreq = x.second;
            else if(x.second == maxFreq) res.push_back(x.first);
        return res;
    }
    
    int DFS(TreeNode* root, unordered_map<int, int>& m){
        if(!root) return 0;
        int l = DFS(root->left, m);
        int r = DFS(root->right, m);
        int sum = root->val + l + r;
        m[sum]++;
        return sum;
    }
};
