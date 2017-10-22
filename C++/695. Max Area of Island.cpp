class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int maxArea = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j]){
                    int area = 0;
                    DFS(grid, i, j, m, n, area, maxArea);
                }
        return maxArea;
    }
    
    void DFS(vector<vector<int>>& grid, int r, int c, int m, int n, int& area, int& maxArea){
        if(r < 0 || c < 0 || r == m || c == n || grid[r][c] == 0){
            maxArea = max(maxArea, area);
            return;
        }
        area++;
        grid[r][c] = 0;
        DFS(grid, r + 1, c, m, n, area, maxArea);
        DFS(grid, r - 1, c, m, n, area, maxArea);
        DFS(grid, r, c + 1, m, n, area, maxArea);
        DFS(grid, r, c - 1, m, n, area, maxArea);
    }
};
