class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0 || rooms[0].size() == 0) return;
        vector<vector<int>>visited(rooms.size(), vector<int>(rooms[0].size()));
        for(int i = 0; i < rooms.size(); i++)
            for(int j = 0; j < rooms[0].size(); j++)
                if(rooms[i][j] == 0) BFS(rooms, i, j, 0, visited);
    }
    
    void BFS(vector<vector<int>>& rooms, int r, int c, int step, vector<vector<int>>& visited){
        if(r < 0 || c < 0 || r >= rooms.size() || c >= rooms[0].size() || visited[r][c] || rooms[r][c] < step) return;
        if(rooms[r][c] != 0) rooms[r][c] = min(rooms[r][c], step);
        visited[r][c] = 1;
        BFS(rooms, r - 1, c, step + 1, visited);
        BFS(rooms, r + 1, c, step + 1, visited);
        BFS(rooms, r, c + 1, step + 1, visited);
        BFS(rooms, r, c - 1, step + 1, visited);
        visited[r][c] = 0;
    }
};

// Further optimize
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0 || rooms[0].size() == 0) return;
        for(int i = 0; i < rooms.size(); i++)
            for(int j = 0; j < rooms[0].size(); j++)
                if(rooms[i][j] == 0) BFS(rooms, i, j, 0);
    }
    
    void BFS(vector<vector<int>>& rooms, int r, int c, int step){
        if(r < 0 || c < 0 || r >= rooms.size() || c >= rooms[0].size() || rooms[r][c] < step) return;
        rooms[r][c] = step;
        BFS(rooms, r - 1, c, step + 1);
        BFS(rooms, r + 1, c, step + 1);
        BFS(rooms, r, c + 1, step + 1);
        BFS(rooms, r, c - 1, step + 1);
    }
};
