class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>>visited(m, vector<int>(n, INT_MAX));
        int minDis = -1;
        string res;
        dfs(maze, ball[0], ball[1], hole, visited, m, n, 0, "", minDis, res);
        return res.empty() ? "impossible" : res;
    }
    
    void dfs(vector<vector<int>>& maze, int r, int c, vector<int>& destination, vector<vector<int>>& visited, int m, int n, 
             int path, string cur, int& minDis, string& res) {
        if (path > visited[r][c]) {
            return;
        }
        visited[r][c] = path;
        // left
        int left = c;
        int leftPath = path;
        string curLeft = cur + "l";
        while (left - 1 >= 0 && maze[r][left - 1] == 0) {
            --left;
            ++leftPath;
            
            if (r == destination[0] && left == destination[1]) {
                updateResult(leftPath, curLeft, minDis, res);
                return;
            }
        }
        if (left != c) {
            dfs(maze, r, left, destination, visited, m, n, leftPath, curLeft, minDis, res);
        }
        // right
        int right = c;
        int rightPath = path;
        string curRight = cur + "r";
        while (right + 1 < n && maze[r][right + 1] == 0) {
            ++right;
            ++rightPath;
            
            if (r == destination[0] && right == destination[1]) {
                updateResult(rightPath, curRight, minDis, res);
                return;
            }
        }
        if (right != c) {
            dfs(maze, r, right, destination, visited, m, n, rightPath, curRight, minDis, res);
        }
        // up
        int up = r;
        int upPath = path;
        string curUp = cur + "u";
        while (up - 1 >= 0 && maze[up - 1][c] == 0) {
            --up;
            ++upPath;
            
            if (up == destination[0] && c == destination[1]) {
                updateResult(upPath, curUp, minDis, res);
                return;
            }
        }
        if (up != r) {
            dfs(maze, up, c, destination, visited, m, n, upPath, curUp, minDis, res);
        }
        // down
        int down = r;
        int downPath = path;
        string curDown = cur + "d";
        while (down + 1 < m && maze[down + 1][c] == 0) {
            ++down;
            ++downPath;
            
            if (down == destination[0] && c == destination[1]) {
                updateResult(downPath, curDown, minDis, res);
                return;
            }
        }
        if (down != r) {
            dfs(maze, down, c, destination, visited, m, n, downPath, curDown, minDis, res);
        }
    }
    
    void updateResult(int path, string cur, int& minDis, string& res) {
        if (minDis == -1 || path < minDis) {
            minDis = path;
            res = cur;
        } else if (path == minDis && cur < res) {
            res = cur;   
        }
    }
};
