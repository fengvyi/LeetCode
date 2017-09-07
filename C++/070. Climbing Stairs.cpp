/**
 * Idea:
 * Get to stair n has two ways:
 * 1. Stand at stair n - 1, take step = 1 forward.
 * 2. Stand at stair n - 2, take step = 2 forward.
 * So the total ways to get to the stair(n) = total ways to stair(n - 1) + total ways to stair(n - 2).
 */
class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n + 1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

// Then we notice that dp[i] only concerns with dp[i - 1] and dp[i - 2], 
// so we could use two variables to replace the array, reduce space to O(1).
class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1, three = 1;
        for(int i = 2; i < n + 1; i++){
            three = one + two;
            one = two;
            two = three;
        }
        return three;
    }
};
