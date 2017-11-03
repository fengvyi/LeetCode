class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // dp[i] is the sum of subarray of in range [i , i + k)
        // nextMax[i] is the maximum value in dp[i : dp.size() - 1]
        // nextIdx[i] is the index of nextMax[i]
        int n = nums.size(), sum = 0, maxRight = 0, idx = 0, maxSum = 0;
        vector<int>res, dp(n - k + 1), nextMax(n - k + 1), nextIdx(n - k + 1);
        // Using a sliding window to get the sum of subarray in range [i , i + k)
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(i >= k) sum -= nums[i - k];
            if(i >= k - 1) dp[i - k + 1] = sum;
        }
        // Starting from end of dp array to get the maximum value after current position
        for(int i = dp.size() - 1; i >= 0; i--){
            if(dp[i] > maxRight) maxRight = dp[i], idx = i;
            nextMax[i] = maxRight;
            nextIdx[i] = idx;
        }
        // Using two pointers i, j to find the result
        // The third entry is determined by nextMax[j + k]
        for(int i = 0; i <= n - 3 * k; i++)
            for(int j = i + k; j <= n - 2 * k; j++){
                sum = dp[i] + dp[j] + nextMax[j + k];
                if(sum > maxSum){
                    maxSum = sum;
                    res = {i, j, nextIdx[j + k]};
                }
            }
        return res;
    }
};
