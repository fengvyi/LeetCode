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
