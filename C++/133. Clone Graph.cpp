/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// DFS
class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>m;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        if(m.count(node) == 0){
            m[node] = new UndirectedGraphNode(node->label);
            for(auto x: node->neighbors) m[node]->neighbors.push_back(cloneGraph(x));
        }
        return m[node];
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
