// Solution 1. DP, O(n^2).
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxlen = 0;
        vector<int>dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++) 
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};

// Solution 2. Binary search, O(nlogn).
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        for(int x: nums){
            int pos = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
            if(pos == dp.size()) dp.push_back(x);
            else dp[pos] = x;
        }
        return dp.size();
    }
};
