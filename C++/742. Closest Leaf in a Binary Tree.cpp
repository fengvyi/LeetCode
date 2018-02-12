class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        // Build Graph
        unordered_map<int, TreeNode*>m;
        unordered_map<int, vector<int>>g;
        buildGraph(g, m, root);
        if(g[k].size() == 1 && !m[k]->left && !m[k]->right) return k; // The nearest leaf node is the root node itself
        // BFS
        vector<int>visited(1001);
        deque<int>q;
        q.push_back(k);
        while(!q.empty()){
            int node = q.front();
            q.pop_front();
            visited[node] = 1;
            bool isEnd = true;
            for(int neigh: g[node]){
                if(!visited[neigh]){
                    q.push_back(neigh);
                    isEnd = false;
                }
            }
            if(isEnd && !m[node]->left && !m[node]->right) return node;
        }
        return 0;
    }
    
    void buildGraph(unordered_map<int, vector<int>>& g, unordered_map<int, TreeNode*>& m, TreeNode* root){
        if(!root) return;
        m[root->val] = root;
        if(root->left){
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            buildGraph(g, m, root->left);
        }
        if(root->right){
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            buildGraph(g, m, root->right);
        }
    }
};
