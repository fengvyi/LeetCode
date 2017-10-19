class Solution {
    struct TreeNode{
        int val;
        int sum;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x, int y): val(x), sum(y), left(NULL), right(NULL){}
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        TreeNode* root = NULL;
        vector<int>res(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) root = buildTree(root, i, nums[i], 0, res);
        return res;
    }
    
    TreeNode* buildTree(TreeNode* root, int i, int val, int count, vector<int>& res){
        if(!root){
            root = new TreeNode(val, 1);
            res[i] = count;
            return root;
        }
        if(val > root->val) root->right = buildTree(root->right, i, val, count + root->sum, res);
        else{
            root->sum++;
            root->left = buildTree(root->left, i, val, count, res);
        }
        return root;
    }
};
