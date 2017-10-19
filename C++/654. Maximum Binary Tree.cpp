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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return DFS(nums, 0, nums.size());
    }
    
    TreeNode* DFS(vector<int>& nums, int l, int r){
        if(l == r) return NULL;
        int maxPos = l;
        for(int i = l; i < r; i++) if(nums[i] > nums[maxPos]) maxPos = i;
        TreeNode* root = new TreeNode(nums[maxPos]);
        root->left = DFS(nums, l, maxPos);
        root->right = DFS(nums, maxPos + 1, r);
        return root;
    }
};

// O(n)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        deque<TreeNode*>q;
        for(auto x: nums){
            TreeNode* p = new TreeNode(x);
            while(!q.empty() && q.back()->val < x) p->left = q.back(), q.pop_back();
            if(!q.empty() && q.back()->val > x) q.back()->right = p;
            q.push_back(p);
        }
        return q.front();
    }
};
