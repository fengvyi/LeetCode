// First version:
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        //Find root in inorder 
        int i = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        //preorder and inorder for each left and right subtree
        vector<int>inorderLeft(inorder.begin(), inorder.begin() + i);
        vector<int>inorderRight(inorder.begin() + i + 1, inorder.end());
        vector<int>preorderLeft(preorder.begin() + 1, preorder.begin() + 1 + i);
        vector<int>preorderRight(preorder.begin() + 1 + i, preorder.end());
        //Build tree
        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }
};

// Then I realized I don't need so much extra memory, and reduced run time from 62ms to 19ms.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd) {
        if(pStart > pEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int i = find(inorder.begin(), inorder.end(), preorder[pStart]) - inorder.begin();
        root->left = helper(preorder, pStart + 1, pStart + i - iStart, inorder, iStart, i - 1);
        root->right = helper(preorder, pStart + i - iStart + 1, pEnd, inorder, i + 1, iEnd);
        return root;
    }
};

// And it can be faster using unordered_map to store the indices first. Run time: from 19ms to 9ms.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>m;
        for(int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    }
    
    TreeNode* helper(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& m) {
        if(pStart > pEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int i = m[preorder[pStart]];
        root->left = helper(preorder, pStart + 1, pStart + i - iStart, inorder, iStart, i - 1, m);
        root->right = helper(preorder, pStart + i - iStart + 1, pEnd, inorder, i + 1, iEnd, m);
        return root;
    }
};
