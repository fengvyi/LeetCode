class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>s;
        auto p = root;
        while(p || !s.empty()){
            if(!p) p = s.top(), s.pop();
            res.push_back(p->val);
            if(p->right) s.push(p->right);
            p = p->left;
        }
        return res;
    }
};
