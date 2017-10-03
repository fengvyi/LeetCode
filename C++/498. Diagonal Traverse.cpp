class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>>dir({{-1, 1}, {1, -1}});
        DFS(matrix, res, 0, 0, m, n, dir, 0);
        return res;
    }
    
    void DFS(vector<vector<int>>& matrix, vector<int>& res, int r, int c, int m, int n, vector<pair<int, int>>& dir, int d){
        if(res.size() == m * n) return;
        res.push_back(matrix[r][c]);
        int R = r + dir[d].first;
        int C = c + dir[d].second;
        if(R < 0 || C < 0 || R >= m || C >= n){
            d = (d + 1) % 2;
            if(R < 0 || R >= m) R = r, C = c + 1;
            if(C < 0 || C >= n) R = r + 1, C = c;
        }
        DFS(matrix, res, R, C, m, n, dir, d);
    }
};
