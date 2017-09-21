class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        for(int i = 0; i < matrix.size(); i++){
            dp.push_back(vector<int>());
            for(int j = 0; j < matrix[0].size(); j++)
                if(i == 0) dp[i].push_back(!j ? matrix[0][0] : matrix[0][j] + dp[0][j - 1]);
                else dp[i].push_back(!j ? matrix[i][j] + dp[i - 1][0] : matrix[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2][col2] - (!row1 ? 0 : dp[row1 - 1][col2]) - (!col1 ? 0 : dp[row2][col1 - 1]) + (!row1 || !col1 ? 0 : dp[row1 - 1][col1 - 1]);
    }
    
private:
    vector<vector<int>>dp;
};
