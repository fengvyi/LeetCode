/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// Recursion
class Solution {
private:
    unordered_map<int, UndirectedGraphNode*>m;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        if(m.count(node->label) == 0){
            m[node->label] = new UndirectedGraphNode(node->label);
            for(auto x: node->neighbors) m[node->label]->neighbors.push_back(cloneGraph(x));
        }
        return m[node->label];
    }
};

// BFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>m;
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        m[node] = root;
        deque<UndirectedGraphNode*>cur;
        deque<UndirectedGraphNode*>next;
        cur.push_back(node);
        while(!cur.empty()){
            UndirectedGraphNode* p = cur.front();
            cur.pop_front();
            for(auto x: p->neighbors){
                if(m.count(x) == 0){
                    UndirectedGraphNode* copy = new UndirectedGraphNode(x->label);
                    m[x] = copy;
                    next.push_back(x);
                }
                m[p]->neighbors.push_back(m[x]);
            }
            if(cur.empty()) swap(cur, next);
        }
        return root;
    }
};

// DFS
class Solution {
private:
    unordered_map<int, UndirectedGraphNode*>created;
    unordered_map<int, int>visited;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode* root= new UndirectedGraphNode(node->label);
        created[node->label] = root;
        DFS(root, node);
        return root;
    }
    
    void DFS(UndirectedGraphNode* root, UndirectedGraphNode* node){
        for(auto x: node->neighbors){
            UndirectedGraphNode* copy;
            if(created.count(x->label)) copy = created[x->label];
            else{
                copy = new UndirectedGraphNode(x->label);
                created[x->label] = copy;
            }
            if(x != node && !visited.count(x->label)) DFS(copy, x);
            root->neighbors.push_back(copy);
            visited[x->label]++;
        }
    }
};
