class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>>dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + nums[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = nums[i] == nums[i - 1] + 1 ? dp[i - 1][0] + nums[i] : dp[i][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
