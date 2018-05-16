class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>>g(N, vector<int>());
        for(auto& e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int>res(N), child(N), visited(N);
        dfs(g, res, child, 0, 0, visited);
        for(auto& x: visited) x = 0;
        dfs(g, res, child, 0, visited, N);
        return res;
    }
    // Sum of the distances of node 0
    void dfs(vector<vector<int>>& g, vector<int>& res, vector<int>& child, int len, int root, vector<int>& visited){
        visited[root] = 1;
        res[0] += len++;
        for(auto& x: g[root]){
            if(visited[x]) continue;
            dfs(g, res, child, len, x, visited);
            child[root] += child[x];
        }
        child[root] += 1;
    }
    // Sum of the distances of node 1 to N - 1
    void dfs(vector<vector<int>>& g, vector<int>& res, vector<int>& child, int root, vector<int>& visited, int N){
        visited[root] = 1;
        for(auto& x: g[root]){
            if(visited[x]) continue;
            res[x] = res[root] - child[x] + N - child[x];
            dfs(g, res, child, x, visited, N);
        }
    }
};
