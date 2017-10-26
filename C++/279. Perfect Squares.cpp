// Non-static DP, 89ms.
class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};

// Static DP, 6ms.
class Solution {
public:
    int numSquares(int n) {
        static vector<int>dp(1, 0);
        for(int i = dp.size(); i <= n; i++){
            dp.push_back(INT_MAX);
            for(int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};
