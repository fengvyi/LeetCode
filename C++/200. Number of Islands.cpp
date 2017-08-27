class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1') count++, BFS(grid, i, j, m, n);
        return count;
    }
    
    void BFS(vector<vector<char>>& grid, int r, int c, int m, int n){
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') return;
        grid[r][c] = '0';
        BFS(grid, r - 1, c, m, n);
        BFS(grid, r + 1, c, m, n);
        BFS(grid, r, c + 1, m, n);
        BFS(grid, r, c - 1, m, n);
    }
};
