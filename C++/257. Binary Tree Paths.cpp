/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DFS
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(!root) return res;
        DFS(root, res, "");
        return res;
    }
    
    void DFS(TreeNode* root, vector<string>& res, string path){
        path += to_string(root->val);
        if(root->left || root->right) path += "->";
        else{
            res.push_back(path);
            return;
        }
        if(root->left) DFS(root->left, res, path);
        if(root->right) DFS(root->right, res, path);
    }
};

// BFS
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(!root) return res;
        deque<pair<TreeNode*, string>>cur;
        deque<pair<TreeNode*, string>>next;
        cur.push_back(make_pair(root, ""));
        while(!cur.empty()){
            auto p = cur.front();
            cur.pop_front();
            p.second += to_string(p.first->val);
            if(p.first->left || p.first->right) p.second += "->";
            else res.push_back(p.second);
            if(p.first->left) next.push_back(make_pair(p.first->left, p.second));
            if(p.first->right) next.push_back(make_pair(p.first->right, p.second));
            if(cur.empty()) swap(cur, next);
        }
        return res;
    }
};
