class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>res;
        int n = graph.size();
        vector<int>loop(n), safe(n), visited(n);
        for(int i = 0; i < n; i++)
            if(isSafe(graph, visited, loop, safe, i)) res.push_back(i);
        return res;
    }
    
    bool isSafe(vector<vector<int>>& graph, vector<int>& visited, vector<int>& loop, vector<int>& safe, int node){
        if(safe[node]) return true;
        if(loop[node] || visited[node]) return false;
        visited[node] = 1;
        bool b = true;
        for(int neigh: graph[node]) b &= isSafe(graph, visited, loop, safe, neigh);
        visited[node] = 0;
        b ? safe[node] = 1 : loop[node] = 1;
        return b;
    }
};
