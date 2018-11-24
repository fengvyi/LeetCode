class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<vector<int>>>dp(maze.size(), vector<vector<int>>(maze[0].size(), vector<int>(4, INT_MAX)));
        int minDis = INT_MAX;
        for(int i = 0; i < 4; i++)
            DFS(maze, i, start[0], start[1], destination[0], destination[1], minDis, 0, dp);
        return minDis == INT_MAX ? -1 : minDis;
    }
    
    bool DFS(vector<vector<int>>& maze, int d, int a, int b, int x, int y, int& minDis, int dis, vector<vector<vector<int>>>& dp){
        if(a < 0 || b < 0 || a == maze.size() || b == maze[0].size() || maze[a][b] == 1) return false;
        if(dis >= minDis || dis >= dp[a][b][d]) return true;
        dp[a][b][d] = min(dp[a][b][d], dis);
        if(!DFS(maze, d, a + directions[d].first, b + directions[d].second, x, y, minDis, dis + 1, dp)){
            if(a == x && b == y){
                minDis = min(minDis, dis);
                return true;
            }
            for(auto dir: nextDir(d))
                DFS(maze, dir, a + directions[dir].first, b + directions[dir].second, x, y, minDis, dis + 1, dp);
        }
        return true;
    }
    
private:
    vector<pair<int, int>>directions;
    vector<int> nextDir(int d){
        if(d == 0 || d == 3) return {1, 2};
        if(d == 1 || d == 2) return {0, 3};
    }
};


class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>>visited(m, vector<int>(n, INT_MAX));
        int minDis = -1;
        dfs(maze, start[0], start[1], destination, visited, m, n, 0, minDis);
        return minDis;
    }
    
    void dfs(vector<vector<int>>& maze, int r, int c, vector<int>& destination, vector<vector<int>>& visited, int m, int n, 
             int path, int& minDis) {
        if (r == destination[0] && c == destination[1]) {
            if (minDis == -1) {
                minDis = path;
            } else {
                minDis = min(minDis, path);
            }
        }
        if (path >= visited[r][c]) {
            return;
        }
        visited[r][c] = path;
        // left
        int left = c;
        int leftPath = path;
        while (left - 1 >= 0 && maze[r][left - 1] == 0) {
            --left;
            ++leftPath;
        }
        if (left != c) {
            dfs(maze, r, left, destination, visited, m, n, leftPath, minDis);
        }
        // right
        int right = c;
        int rightPath = path;
        while (right + 1 < n && maze[r][right + 1] == 0) {
            ++right;
            ++rightPath;
        }
        if (right != c) {
            dfs(maze, r, right, destination, visited, m, n, rightPath, minDis);
        }
        // up
        int up = r;
        int upPath = path;
        while (up - 1 >= 0 && maze[up - 1][c] == 0) {
            --up;
            ++upPath;
        }
        if (up != r) {
            dfs(maze, up, c, destination, visited, m, n, upPath, minDis);
        }
        // down
        int down = r;
        int downPath = path;
        while (down + 1 < m && maze[down + 1][c] == 0) {
            ++down;
            ++downPath;
        }
        if (down != r) {
            dfs(maze, down, c, destination, visited, m, n, downPath, minDis);
        }
    }
};
