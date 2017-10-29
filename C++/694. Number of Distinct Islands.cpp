// Solution 1.
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_map<int, vector<vector<int>>>mp;
        int count = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1){
                    int area = 0;
                    DFS(grid, i, j, m, n, area);
                    bool equal = false;
                    for(auto x: mp[area]){
                        int S = 0;
                        vector<vector<int>>visited(m, vector<int>(n));
                        DFS(grid, i, j, x[0], x[1], m, n, S, visited);
                        if(S == area){ equal = true; break; }
                    }
                    if(!equal) count++, mp[area].push_back({i, j});
                }
        return count;
    }
    
    void DFS(vector<vector<int>>& grid, int r, int c, int m, int n, int& area){
        if(r < 0 || c < 0 || r == m || c == n || !grid[r][c] || grid[r][c] == 2) return;
        area++;
        grid[r][c] = 2;
        for(int i = 0; i < 4; i++) DFS(grid, r + d[i][0], c + d[i][1], m, n, area);
    }
    
    void DFS(vector<vector<int>>& grid, int r, int c, int R, int C, int m, int n, int& S, vector<vector<int>>& visited){
        if(r < 0 || c < 0 || R < 0 || C < 0 || r == m || R == m || c == n || C == n || visited[r][c]) return;
        if(!grid[r][c] && !grid[R][C] || grid[r][c] != grid[R][C]) return;
        S++;
        visited[r][c] = 1;
        for(int i = 0; i < 4; i++) DFS(grid, r + d[i][0], c + d[i][1], R + d[i][0], C + d[i][1], m, n, S, visited);
    }

private:
    vector<vector<int>>d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};

// Solution 2. Using set.
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int count = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1){
                    vector<vector<int>>island;
                    DFS(grid, i, j, i, j, m, n, island);
                    s.insert(island);
                }
        return s.size();
    }
    
    void DFS(vector<vector<int>>& grid, int i, int j, int r, int c, int m, int n, vector<vector<int>>& island){
        if(r < 0 || c < 0 || r == m || c == n || !grid[r][c] || grid[r][c] == 2) return;
        island.push_back({r - i, c - j});
        grid[r][c] = 2;
        for(int k = 0; k < 4; k++) DFS(grid, i, j, r + d[k][0], c + d[k][1], m, n, island);
    }
    
private:
    set<vector<vector<int>>>s;
    vector<vector<int>>d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};
