class Solution {
public:
    int knightDialer(int N) {
        vector<long>dp(10, 1);
        vector<long>next(10, 1);
        vector<int>ways(10, 2);  // Number of ways we can jump from position X
        ways[5] = 0;
        ways[4] = 3;
        ways[6] = 3;
        long res = 10;
        while (--N) {
            res = 0;
            for (auto& x: dp) {
                x %= 1000000007;
            }
            for (int j = 0; j < 10; ++j) {
                res += dp[j] * ways[j];
                res %= 1000000007;
            }
            next[1] = dp[6] + dp[8];
            next[2] = dp[7] + dp[9];
            next[3] = dp[4] + dp[8];
            next[4] = dp[3] + dp[9] + dp[0];
            next[6] = dp[1] + dp[7] + dp[0];
            next[7] = dp[2] + dp[6];
            next[8] = dp[1] + dp[3];
            next[9] = dp[2] + dp[4];
            next[0] = dp[4] + dp[6];
            swap(dp, next);
        }
        return res;
    }
};
