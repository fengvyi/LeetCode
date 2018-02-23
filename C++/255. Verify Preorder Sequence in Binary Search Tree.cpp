class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size(), INT_MIN, INT_MAX);
    }
    
    bool dfs(vector<int>& preorder, int l, int r, int minVal, int maxVal){
        if(l >= r) return true;
        int root = preorder[l], mid = r;
        for(int i = l; i < r; i++)
            if(preorder[i] < minVal || preorder[i] > maxVal) return false;
            else if(preorder[i] > root && mid == r) mid = i;
        return dfs(preorder, l + 1, mid, minVal, root) && dfs(preorder, mid, r, root, maxVal);
    }
};
