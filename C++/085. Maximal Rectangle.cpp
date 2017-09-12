class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '1') maxArea = max(maxArea, BFS(matrix, i, j));
        return maxArea;
    }
    
    int BFS(vector<vector<char>>& matrix, int r, int c){
        int row = r - 1, maxArea = 0;
        while(row >= 0 && matrix[row][c] == '1') row--;
        for(int i = c; i >= 0 && matrix[r][i] == '1'; i--){
            for(int j = row + 1; j <= r; j++)
                if(matrix[j][i] == '0') row = max(row, j);
            maxArea = max(maxArea, (r - row) * (c - i + 1));
        }
        return maxArea;
    }
};
