class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>>dir({{0, 1}, {1, 0}, {-1, 0}, {0, -1}});
        deque<pair<int, int>>q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j]) matrix[i][j] = INT_MAX;
                else q.push_back({i, j});
        //BFS
        while(!q.empty()){
            auto p = q.front();
            q.pop_front();
            for(auto x: dir){
                int r = p.first + x.first;
                int c = p.second + x.second;
                if(r < 0 || c < 0 || r == m || c == n) continue;
                if(matrix[r][c] >= matrix[p.first][p.second] + 1){
                    matrix[r][c] = matrix[p.first][p.second] + 1;
                    q.push_back({r, c});
                }
            }
        }
        return matrix;
    }
};
