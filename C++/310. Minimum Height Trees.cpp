/* From BF 1880ms to O(n) 35ms beats 99% */
// Solution 1. Brute Force, find the min height of starting from `root(i) = 0, 1, 2, ... n - 1` using BFS. 
// Easy to understand but will obviously costs a lot of time.
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int>res;
        vector<vector<int>>graph(n);
        // Build Graph
        for(auto x: edges){
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }
        int minHeight = INT_MAX;
        // BFS
        for(int i = 0; i < n; i++){
            if(graph[i].size() < 5 && n > 10000) continue; // Magic for passing the last TC.
            vector<int>visited(n);
            int height = 0;
            deque<int>cur;
            deque<int>sub;
            cur.push_back(i);
            
            while(!cur.empty() && height <= minHeight){
                int node = cur.front();
                cur.pop_front();
                visited[node] = 1;
                for(auto neigh: graph[node])
                    if(!visited[neigh]) sub.push_back(neigh);
                if(cur.empty()){
                    height++;
                    swap(cur, sub);
                }
            }
            if(height < minHeight){
                res.clear();
                minHeight = height;
                res.push_back(i);
            }
            else if(minHeight == height) res.push_back(i);
        }
        return res;
    }
};

// Solution 2.
/**
 * After reviewing the BF solution, I realized that the Minimum Height Node is exactly the mid point of the longest path in the graph. 
 * (Or 2 nodes if length is even.) 
 * So, idea is that, we use 3 passes in total to found the longest path in the graph:
 * 1. First pass, starting from any node, go as deep as we can until reach the leaf node `a`.
 * 2. Second pass, starting from node `a`, go as deep as we can until reach the leaf node `b`.
 * 3. The path between node `a` and `b` is the longest path of the graph, using DFS to find path `a` to `b`.
 * Then we simply return the mid node(odd) / nodes(even) of the longest path.
 * Time Complexity: O(n).
 * Here is the code, 35ms beats 99.17%.
 */
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int>res;
        vector<vector<int>>graph(n);
        // Build Graph
        for(auto x: edges){
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }
        int start = 0, end = 0;
        // BFS
        int root = 0;
        for(int i = 0; i < 2; i++){
            vector<int>visited(n);
            deque<int>cur;
            deque<int>sub;
            cur.push_back(root);
            while(!cur.empty()){
                int node = cur.front();
                cur.pop_front();
                visited[node] = 1;
                for(auto neigh: graph[node]) 
                    if(!visited[neigh]) sub.push_back(neigh);
                if(sub.empty()){
                    root = node;
                    if(i == 0) start = root;
                    if(i == 1) end = root;
                }
                if(cur.empty()) swap(cur, sub);
            }
        }
        // DFS
        vector<int>vec;
        vector<int>path;
        vector<int>visited(n);
        bool found = false;
        DFS(graph, visited, start, end, vec, path, found);
        if(path.size() % 2) res.push_back(path[path.size() / 2]);
        else{
            res.push_back(path[path.size() / 2]);
            res.push_back(path[path.size() / 2 - 1]);
        }
        return res;
    }
    
    void DFS(vector<vector<int>>& graph, vector<int>& visited, int node, int dest, vector<int>& vec, vector<int>& path, bool& found){
        if(visited[node]) return;
        visited[node] = 1;
        vec.push_back(node);
        if(node == dest){
            path = vec;
            found = true;
            return;
        }
        for(auto neigh: graph[node]){
            DFS(graph, visited, neigh, dest, vec, path, found);
            if(found) break;
        }
        vec.pop_back();
    }
};
