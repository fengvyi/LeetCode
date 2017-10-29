class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]
        int sum = 0;
        for(auto x: nums) sum += x;
        if(sum % 2) return false;
        vector<vector<bool>>dp(nums.size(), vector<bool>(sum / 2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i < nums.size(); i++)
            for(int j = 0; j < sum / 2 + 1; j++)
                dp[i][j] = dp[i - 1][j] || ((j >= nums[i]) ? dp[i - 1][j - nums[i]] : 0);
        return dp[nums.size() - 1][sum / 2];
    }
};
