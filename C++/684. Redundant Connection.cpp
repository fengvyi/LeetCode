class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int tag = 1;
        unordered_map<int, int>id;
        unordered_map<int, vector<int>>g;
        for(auto x: edges){
            int u = x[0], v = x[1];
            g[u].push_back(v);
            g[v].push_back(u);
            if(id[u] && id[v] && id[u] == id[v]) return x;
            else if(!id[u] && !id[v]) id[u] = id[v] = tag++;
            else if(id[u]) DFS(g, id, v, id[u]);
            else id[u] = id[v];
        }
    }
    
    void DFS(unordered_map<int, vector<int>>& g, unordered_map<int, int>& id, int root, int tag){
        if(id[root] == tag) return;
        id[root] = tag;
        for(auto x: g[root]) DFS(g, id, x, tag);
    }
};
