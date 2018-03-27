class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        dfs(graph, res, {}, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> path, int node){
        path.push_back(node);
        if(graph[node].size() == 0) res.push_back(path);
        for(int neigh: graph[node]) dfs(graph, res, path, neigh);
    }
};
