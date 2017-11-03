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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int>res;
        priority_queue<pair<double, int>>pq;
        DFS(root, target, k, pq);
        while(!pq.empty()) res.push_back(pq.top().second), pq.pop();
        return res;
    }
    
    void DFS(TreeNode* root, double target, int k, priority_queue<pair<double, int>>& pq){
        if(!root) return;
        pq.push({abs(root->val - target), root->val});
        if(pq.size() > k) pq.pop();
        DFS(root->left, target, k, pq);
        DFS(root->right, target, k, pq);
    }
};
