class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int>dp(26);
        int len = 0;
        for(int i = 0; i < p.size(); i++){
            len = (i > 0 && (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25)) ? len + 1 : 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], len);
        }
        int sum = 0;
        for(int x: dp) sum += x;
        return sum;
    }
};
