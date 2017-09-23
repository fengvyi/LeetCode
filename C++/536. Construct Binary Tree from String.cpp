class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s.empty()) return NULL;
        int i = 0;
        while(i < s.size() && (isdigit(s[i]) || s[i] == '-')) i++;
        TreeNode* root = new TreeNode(stoi(s.substr(0, i)));
        int j = i, k = 0;
        while(j < s.size()){
            if(s[j] == '(') k++;
            else if(s[j] == ')') k--;
            if(k == 0){
                if(!root->left) root->left = str2tree(s.substr(i + 1, j - i - 1));
                else root->right = str2tree(s.substr(i + 1, j - i - 1));
                i = j + 1;
            }
            j++;
        }
        return root;
    }
};
