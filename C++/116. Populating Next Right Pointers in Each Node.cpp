/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// Solution 1. Works for any knid of tree, O(n) space.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        deque<TreeLinkNode*>cur;
        deque<TreeLinkNode*>next;
        cur.push_back(root);
        while(!cur.empty()){
            TreeLinkNode* node = cur.front();
            cur.pop_front();
            node->next = cur.empty() ? NULL : cur.front();
            if(node->left) next.push_back(node->left);
            if(node->right) next.push_back(node->right);
            if(cur.empty()) swap(cur, next);
        }
    }
};

// Solution 2. O(1) space.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* cur(root), *next;
        while(cur){
            next = cur->left;
            while(cur){
                if(cur->left){
                    cur->left->next = cur->right;
                    cur->right->next = cur->next ? cur->next->left : NULL;
                }
                cur = cur->next;
            }
            cur = next;
        }
    }
};
