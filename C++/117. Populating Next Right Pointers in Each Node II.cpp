/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 // O(n) space
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

// Based on this thread (https://discuss.leetcode.com/topic/8447/simple-solution-using-constant-space).
// I modified it a bit to be a real constant space solution.
// O(1) space 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode tempChild(0);
        TreeLinkNode* currentChild;
        while(root){
            tempChild.next = NULL;
            currentChild = &tempChild;
            while(root){
                if(root->left) { currentChild->next = root->left; currentChild = currentChild->next;}
                if(root->right) { currentChild->next = root->right; currentChild = currentChild->next;}
                root = root->next;
            }
            root = tempChild.next;
        }
    }
};
