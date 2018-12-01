// DFS
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return !p && !q;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// BFS
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>pq, qq;
        pq.push(p);
        qq.push(q);
        while(!pq.empty() && !qq.empty()) {
            auto a = pq.front();
            pq.pop();
            auto b = qq.front();
            qq.pop();
            if (!a || !b) {
                if (!a && !b) {
                    continue;
                } else {
                    return false;
                }
            }
            
            if (a->val != b->val) {
                return false;
            }
            
            pq.push(a->left);
            pq.push(a->right);
            
            qq.push(b->left);
            qq.push(b->right);
        }
        return true;
    }
};
