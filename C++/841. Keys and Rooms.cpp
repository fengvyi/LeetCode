// DFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = 0, n = rooms.size();
        vector<int>visited(n);
        dfs(rooms, 0, visited, count);
        return count == n;
    }
    
    void dfs(vector<vector<int>>& rooms, int pos, vector<int>& visited, int& count){
        if(visited[pos]) return;
        count++;
        visited[pos] = 1;
        for(auto x: rooms[pos]) dfs(rooms, x, visited, count);
    }
};

// BFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = 0, n = rooms.size();
        vector<int>visited(n);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(visited[x]) continue;
            visited[x] = 1;
            count++;
            for(auto neigh: rooms[x]) q.push(neigh);
        }
        return count == n;
    }
};
