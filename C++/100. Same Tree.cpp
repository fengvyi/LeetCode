// DFS
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// BFS
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<TreeNode*>q1, q2;
        if(p) q1.push_back(p);
        if(q) q2.push_back(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* a = q1.front();
            TreeNode* b = q2.front();
            q1.pop_front();
            q2.pop_front();
            if(a->val != b->val) return false;
            if((a->left || b->left) && (!a->left || !b->left)) return false;
            if((a->right || b->right) && (!a->right || !b->right)) return false;
            if(a->left) q1.push_back(a->left);
            if(a->right) q1.push_back(a->right);
            if(b->left) q2.push_back(b->left);
            if(b->right) q2.push_back(b->right);
        }
        return q1.empty() && q2.empty();
    }
};
