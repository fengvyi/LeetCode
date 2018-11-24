// Solution 1
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

// Solution 2
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if (edges.empty()) {
            return {};
        }
        vector<vector<int>>g(1001);
        vector<int>visited(1001);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            
            if (!dfs(g, e[0], e[1], visited)) {
                return e;
            }
        }
        return {};
    }
    
    bool dfs(vector<vector<int>>& g, int node, int from, vector<int>& visited) {
        if (visited[node]) {
            return false;
        }
        visited[node] = 1;
        bool res = true;
        for (int& x: g[node]) {
            if (x != from) {
                res &= dfs(g, x, node, visited);
            }
        }
        visited[node] = 0;
        return res;
    }
};

// Solution 3
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>root(1001);
        
        for (int i = 0; i < 1001; ++i) {
            root[i] = i;
        }
        
        for(auto& pair: edges) {
            int a = pair[0];
            int b = pair[1];

            while (a != root[a]) a = root[a];
            while (b != root[b]) b = root[b];
            
            if (a == b) {
                return pair;
            } else {
                root[a] = b;
            }
        }
        return {};
    }
};
