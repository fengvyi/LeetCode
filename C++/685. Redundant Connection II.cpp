class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int>res;
        unordered_map<int, int>parent;
        unordered_map<int, vector<int>>g;
        // c0: the last edge to form a circle
        // c1, c2: parents of the node who has two parents
        vector<int>c0, c1, c2;
        int rootCandidate = 0, root = 0, count = 0;
        for(auto x: edges){
            int u = x[0], v = x[1];
            if(parent[v] > 0){
                c1 = x;
                c2 = {parent[v], v};
            }
            if(!parent[u]){
                rootCandidate++;
                parent[u] = -1;
            }
            if(parent[v] == -1) rootCandidate--;
            parent[v] = u;
            if(rootCandidate == 0) c0 = x, rootCandidate = -1; // No valid root can be found, circle detected
            g[u].push_back(v);
        }
        for(auto x: parent) if(x.second == -1) root = x.first;
        int nodes = parent.size();
        vector<int>visited(nodes + 1);
        return !root ? c0 : (!hasCircle(g, -1, root, c1, visited, count) && count == nodes) ? c1 : c2;
    }
    
    bool hasCircle(unordered_map<int, vector<int>>& g, int from, int root, vector<int>c, vector<int>& visited, int& count){
        if(from == c[0] && root == c[1]) return false;
        if(visited[root]) return true;
        count++;
        visited[root] = 1;
        bool foundCircle = false;
        for(auto x: g[root]) foundCircle |= hasCircle(g, root, x, c, visited, count);
        return foundCircle;
    }
};
