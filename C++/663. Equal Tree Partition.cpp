class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        vector<int>v;
        int sum = DFS(root, v);
        v.pop_back();
        return !(sum % 2) && find(v.begin(), v.end(), sum / 2) != v.end();
    }
    
    int DFS(TreeNode* root, vector<int>& v){
        if(!root) return 0;
        int l = DFS(root->left, v);
        int r = DFS(root->right, v);
        int sum = root->val + l + r;
        v.push_back(sum);
        return sum;
    }
};
