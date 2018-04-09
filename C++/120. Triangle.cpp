// Bottom-up
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n + 1);
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        return dp[0];
    }
};

// Top-down
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n);
        for(int i = 0; i < n; i++){
            if(i != 0) dp[i] = dp[i - 1] + triangle[i][i];
            for(int j = i - 1; j > 0; j--)
                dp[j] = triangle[i][j] + min(dp[j], dp[j - 1]);
            dp[0] = dp[0] + triangle[i][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
