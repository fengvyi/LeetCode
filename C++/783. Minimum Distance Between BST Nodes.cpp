// Recursive
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* pre = NULL;
        DFS(root, pre, minDiff);
        return minDiff;
    }
    
    void DFS(TreeNode* root, TreeNode*& pre, int& minDiff){
        if(!root) return;
        DFS(root->left, pre, minDiff);
        if(pre) minDiff = min(minDiff, abs(root->val - pre->val));
        pre = root;
        DFS(root->right, pre, minDiff);
    }
};

// Non-recursive
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        stack<TreeNode*>s;
        TreeNode* p = root, *pre = NULL;
        while(!s.empty() || p){
            while(p){
                s.push(p);
                p = p->left;
            }
            if(pre) minDiff = min(minDiff, abs(s.top()->val - pre->val));
            pre = s.top();
            s.pop();
            p = pre->right;
        }
        return minDiff;
    }
};
