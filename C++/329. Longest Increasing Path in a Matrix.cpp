class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size() , n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        vector<vector<int>>visited(m, vector<int>(n));
        int maxlen = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                maxlen = max(maxlen, DFS(matrix, visited, dp, i, j, m, n));
        return maxlen;
    }
    
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& visited, vector<vector<int>>& dp, int r, int c, int m, int n){
        if(visited[r][c]) return 0;
        if(dp[r][c]) return dp[r][c];
        visited[r][c] = 1;
        int up(1), down(1), left(1), right(1);
        if(r - 1 >= 0 && matrix[r - 1][c] > matrix[r][c])     up = DFS(matrix, visited, dp, r - 1, c, m, n) + 1;
        if(r + 1 < m  && matrix[r + 1][c] > matrix[r][c])   down = DFS(matrix, visited, dp, r + 1, c, m, n) + 1;
        if(c - 1 >= 0 && matrix[r][c - 1] > matrix[r][c])   left = DFS(matrix, visited, dp, r, c - 1, m, n) + 1;
        if(c + 1 < n  && matrix[r][c + 1] > matrix[r][c])  right = DFS(matrix, visited, dp, r, c + 1, m, n) + 1;
        visited[r][c] = 0;
        dp[r][c] = max(up, max(down, max(left, right)));
        return dp[r][c];
    }
};
