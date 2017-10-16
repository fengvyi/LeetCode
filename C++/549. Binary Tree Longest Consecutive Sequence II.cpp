class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int maxlen = 0;
        DFS(root, maxlen);
        return maxlen;
    }
    
    pair<int, int> DFS(TreeNode* root, int& maxlen){
        if(!root) return {0, 0};
        int iL = 1, dL = 1, iR = 1, dR = 1;
        auto l = DFS(root->left, maxlen);
        auto r = DFS(root->right, maxlen);
        if(root->left && root->left->val == root->val + 1) iL += l.first;
        if(root->left && root->left->val == root->val - 1) dL += l.second;
        if(root->right && root->right->val == root->val + 1) iR += r.first;
        if(root->right && root->right->val == root->val - 1) dR += r.second;
        maxlen = max(maxlen, max(iL + dR - 1, iR + dL - 1));
        return {max(iL, iR), max(dL, dR)};
    }
};
