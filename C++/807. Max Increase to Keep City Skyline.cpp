class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>rowMax(m);
        vector<int>colMax(n);
        // Store the maximum value of each row and column
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        // Sum up the difference
        int sum = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                sum += min(rowMax[i], colMax[j]) - grid[i][j];
        return sum;
    }
};
