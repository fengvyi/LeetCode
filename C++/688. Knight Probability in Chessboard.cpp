class Solution {
private:
    unordered_map<int, unordered_map<int, unordered_map<int, double>>>dp;
public:
    double knightProbability(int N, int K, int r, int c) {
        if(dp.count(r) && dp[r].count(c) && dp[r][c].count(K)) return dp[r][c][K];
        if(r < 0 || r >= N || c < 0 || c >= N) return 0;
        if(K == 0) return 1;
        double total = knightProbability(N, K - 1, r - 1, c - 2) + knightProbability(N, K - 1, r - 2, c - 1) 
                     + knightProbability(N, K - 1, r - 1, c + 2) + knightProbability(N, K - 1, r - 2, c + 1) 
                     + knightProbability(N, K - 1, r + 1, c + 2) + knightProbability(N, K - 1, r + 2, c + 1) 
                     + knightProbability(N, K - 1, r + 1, c - 2) + knightProbability(N, K - 1, r + 2, c - 1);
        double res = total / 8;
        dp[r][c][K] = res;
        return res;
    }
};
