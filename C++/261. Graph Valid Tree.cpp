// Solution 1. DFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto x: edges){
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }
        vector<int>visited(n);
        if(findCircle(graph, visited, -1, 0)) return false;
        for(auto x: visited) if(!x) return false;
        return true;
    }
    
    bool findCircle(vector<vector<int>>& graph, vector<int>& visited, int from, int node){
        if(visited[node]) return true;
        visited[node] = 1;
        bool circle = false;
        for(auto x: graph[node])
            if(x != from){
                circle |= findCircle(graph, visited, node, x);
                if(circle) return true;
            }
        return false;
    }
};

// Solution 2. Union Find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<int>root(n, 0);
        for(int i = 0; i < n; i++) root[i] = i;
        for(int i = 0; i < edges.size(); i++){
            int x = edges[i].first;
            int y = edges[i].second;
            while(root[x] != x) x = root[x];
            while(root[y] != y) y = root[y];
            if(x == y) return false;
            root[y] = x;
        }
        return true;
    }
};
