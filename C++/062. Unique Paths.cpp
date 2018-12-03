class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n));
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int i = 0; i < n; i++) dp[0][i] = 1;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));
        dp[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] += dp[i -  1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j -  1];
            }
        }
        return dp[n - 1];
    }
};
