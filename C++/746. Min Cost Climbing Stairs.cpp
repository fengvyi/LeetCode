// Recursion: `dp[i] = min{dp[i - 1], dp[i - 2]} + cost[i];`
// A straightforward solution is:
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        return min(dp[n - 2], dp[n - 1]);
    }
};

// If we take a look at the solution above, we can see the result dp[i] only depends on previous 2 steps(dp[i - 1] and dp[i - 2]).
// So we can replace the 'dp' array with 2 variables.
// Here is the final solution:
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), a = cost[0], b = cost[1], c;
        for(int i = 2; i < n; i++, a = b, b = c)
            c = min(a, b) + cost[i];
        return min(a, b);
    }
};
