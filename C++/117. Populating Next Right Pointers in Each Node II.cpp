/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
// Solution 1. Works for any kind of tree, O(n) space. 
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
        TreeLinkNode head(0);
        TreeLinkNode* pre = &head, *cur;
        pre->next = root;
        while(pre->next){
            cur = pre->next;
            while(cur){
                if(cur->left){
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if(cur->right){
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            pre->next = NULL;
            pre = &head;
        }
    }
};
