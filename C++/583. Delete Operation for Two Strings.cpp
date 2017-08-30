class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
        vector<vector<int>>dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for(int i = 0; i <= word1.size(); i++)
            for(int j = 0; j <= word2.size(); j++)
                dp[i][j] = (!i || !j) ? 0 : (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
        int LCS = dp[word1.size()][word2.size()];
        return (word1.size() - LCS) + (word2.size() - LCS);
    }
};
