class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sum = 0, minDis = INT_MAX;
        for(auto x: grid)
            for(auto y: x) if(y == 1) sum++;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 0) BFS(grid, m, n, i, j, sum, minDis);
        return minDis == INT_MAX ? -1 : minDis;
    }
    
    void BFS(vector<vector<int>>& grid, int m, int n, int r, int c, int sum, int& minDis){
        int count = 0;
        vector<vector<int>>visited(m, vector<int>(n));
        vector<pair<int, int>>dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        deque<pair<int, int>>cur;
        deque<pair<int, int>>next;
        cur.push_back({r, c});
        visited[r][c] = 1;
        int level = 1, dis = 0;
        while(count < sum && !cur.empty()){
            auto p = cur.front();
            cur.pop_front();
            for(int i = 0; i < 4; i++){
                int R = p.first + dir[i].first;
                int C = p.second + dir[i].second;
                if(R < 0 || C < 0 || R == m || C == n || visited[R][C]) continue;
                visited[R][C] = 1;
                if(grid[R][C] == 1){
                    dis += level;
                    count++;
                }
                if(grid[R][C] == 0) next.push_back({R, C});
            }
            if(cur.empty()){
                level++;
                swap(cur, next);
            }
        }
        if(count == sum) minDis = min(minDis, dis);
    }
};
