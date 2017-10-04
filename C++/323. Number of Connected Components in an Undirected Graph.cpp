// DFS
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>visited(n);
        for(auto x: edges){
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }
        int label = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            label++;
            DFS(graph, i, visited);
        }
        return label;
    }
    
    void DFS(vector<vector<int>>& graph, int root, vector<int>& visited){
        if(visited[root]) return;
        visited[root] = 1;
        for(auto neigh: graph[root])
            if(!visited[neigh]) DFS(graph, neigh, visited);
    }
};

// BFS
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>>graph(n);
        vector<int>visited(n);
        for(auto x: edges){
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }
        int label = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            label++;
            deque<int>q;
            q.push_back(i);
            while(!q.empty()){
                int node = q.front();
                q.pop_front();
                visited[node] = 1;
                for(auto neigh: graph[node])
                    if(!visited[neigh]) q.push_back(neigh);
            }
        }
        return label;
    }
};
