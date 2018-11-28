// See detailed explanation of that problem in discuss.
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        for(int i = 0; i < matrix.size(); i++){
            dp.push_back(vector<int>());
            for(int j = 0; j < matrix[0].size(); j++)
                if(i == 0)
                    if(j == 0) dp[i].push_back(matrix[0][0]);
                    else dp[i].push_back(matrix[0][j] + dp[0][j - 1]);
                else
                    if(j == 0) dp[i].push_back(matrix[i][j] + dp[i - 1][0]);
                    else dp[i].push_back(matrix[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = (row1 == 0) ? 0 : dp[row1 - 1][col2];
        int b = (col1 == 0) ? 0 : dp[row2][col1 - 1];
        int c = (row1 == 0 || col1 == 0) ? 0 : dp[row1 - 1][col1 - 1];
        return dp[row2][col2] - a - b + c;
    }
    
private:
    vector<vector<int>>dp;
};

// Or a more concise one, 7 lines.
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int m = matrix.size(), n = matrix[0].size();
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
    
private:
    vector<vector<int>>dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */


