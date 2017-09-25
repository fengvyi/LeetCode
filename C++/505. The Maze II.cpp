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
