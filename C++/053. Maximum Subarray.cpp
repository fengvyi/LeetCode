class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i] = max(dp[i - 1] + A[i], A[i])
        vector<int>dp(nums.size());
        dp[0] = nums[0];
        int maxSum = dp[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

// Then we notice dp[i] only depends on dp[i - 1], so actually we only need one variable here to replace the array.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int maxSum = dp;
        for(int i = 1; i < nums.size(); i++){
            dp = max(dp + nums[i], nums[i]);
            maxSum = max(maxSum, dp);
        }
        return maxSum;
    }
};
