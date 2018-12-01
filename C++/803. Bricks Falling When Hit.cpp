class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int>res;
        int m = grid.size(), n = grid[0].size();
        for (auto& v: hits) {
            int r = v[0], c = v[1], count = 0;
            grid[r][c] = 0;
            if(!reachTop(grid, r - 1, c, m, n)) {
                erase(grid, r - 1, c, m, n, count);
            }
            if(!reachTop(grid, r + 1, c, m, n)) {
                erase(grid, r + 1, c, m, n, count);
            }
            if(!reachTop(grid, r, c - 1, m, n)) {
                erase(grid, r, c - 1, m, n, count);
            }
            if(!reachTop(grid, r, c + 1, m, n)) {
                erase(grid, r, c + 1, m, n, count);
            }
            res.push_back(count);
        }
        return res;
    }
    
    bool reachTop(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || c < 0 || r == m || c == n || grid[r][c] == 0) {
            return false;
        }
        if (r == 0) {
            return true;
        }
        int tmp = grid[r][c];
        grid[r][c] = 0;
        bool res = reachTop(grid, r + 1, c, m, n) || reachTop(grid, r, c + 1, m, n)
                || reachTop(grid, r - 1, c, m, n) || reachTop(grid, r, c - 1, m, n);
        grid[r][c] = tmp;
        return res;
    }
    
    void erase(vector<vector<int>>& grid, int r, int c, int m, int n, int& count) {
        if (r < 0 || c < 0 || r == m || c == n || grid[r][c] == 0) {
            return;
        }
        ++count;
        grid[r][c] = 0;
        erase(grid, r + 1, c, m, n, count);
        erase(grid, r - 1, c, m, n, count);
        erase(grid, r, c + 1, m, n, count);
        erase(grid, r, c - 1, m, n, count);
    }
};
