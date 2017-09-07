class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for(int i = 1; i < n; i++) dp[0][i] = grid[0][i] + dp[0][i - 1];
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        return dp[m - 1][n - 1];
    }
};
