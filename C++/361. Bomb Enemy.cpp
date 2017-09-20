class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int maxKill = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '0') maxKill = max(maxKill, getKills(grid, i, j));
        return maxKill;
    }
    
    int getKills(vector<vector<char>>& grid, int r, int c){
        int m = grid.size(), n = grid[0].size(), count = 0;
        int up = r - 1, down = r + 1, left = c - 1, right = c + 1;
        while(up >= 0 && grid[up][c] != 'W') if(grid[up--][c] == 'E') count++;
        while(down < m && grid[down][c] != 'W') if(grid[down++][c] == 'E') count++;
        while(left >= 0 && grid[r][left] != 'W') if(grid[r][left--] == 'E') count++;
        while(right < n && grid[r][right] != 'W') if(grid[r][right++] == 'E') count++;
        return count;
    }
};
