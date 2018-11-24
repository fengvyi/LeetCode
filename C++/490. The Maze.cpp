class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>>visited(m, vector<int>(n));
        return dfs(maze, start[0], start[1], destination, visited, m, n);
    }
    
    bool dfs(vector<vector<int>>& maze, int r, int c, vector<int>& destination, vector<vector<int>>& visited, int m, int n) {
        if (r == destination[0] && c == destination[1]) {
            return true;
        }
        if (visited[r][c]) {
            return false;
        }
        visited[r][c] = 1;
        bool res = false;
        // left
        int left = c;
        while (left - 1 >= 0 && maze[r][left - 1] == 0) --left;
        if (left != c) {
            res |= dfs(maze, r, left, destination, visited, m, n);
        }
        // right
        int right = c;
        while (right + 1 < n && maze[r][right + 1] == 0) ++right;
        if (right != c) {
            res |= dfs(maze, r, right, destination, visited, m, n);
        }
        // up
        int up = r;
        while (up - 1 >= 0 && maze[up - 1][c] == 0) --up;
        if (up != r) {
            res |= dfs(maze, up, c, destination, visited, m, n);
        }
        // down
        int down = r;
        while (down + 1 < m && maze[down + 1][c] == 0) ++down;
        if (down != r) {
            res |= dfs(maze, down, c, destination, visited, m, n);
        }
        
        return res;
    }
};
