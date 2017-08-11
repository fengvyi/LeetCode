/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        deque<TreeLinkNode*>cur;
        deque<TreeLinkNode*>sub;
        cur.push_back(root);
        while(!cur.empty()){
            TreeLinkNode* node = cur.front();
            cur.pop_front();
            node->next = cur.empty() ? NULL : cur.front();
            if(node->left) sub.push_back(node->left);
            if(node->right) sub.push_back(node->right);
            if(cur.empty()) swap(cur, sub);
        }
    }
};

// Share a smart O(1) space solution from this thread: https://discuss.leetcode.com/topic/2202/a-simple-accepted-solution.
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}
