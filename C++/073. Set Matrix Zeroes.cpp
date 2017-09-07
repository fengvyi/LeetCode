// Top-down
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size(), col0 = 1;
        for(int i = 0; i < m; i++){
            if(!matrix[i][0]) col0 = 0;
            for(int j = 1; j < n; j++)
                if(!matrix[i][j]) matrix[0][j] = matrix[i][0] = 0;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++)
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            if(!col0) matrix[i][0] = 0;
        }
        for(auto& x: matrix[0]) if(!matrix[0][0]) x = 0;
        if(!col0) matrix[0][0] = 0;
    }
};

// Bottom-up
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size(), col0 = 1;
        for(int i = 0; i < m; i++){
            if(!matrix[i][0]) col0 = 0;
            for(int j = 1; j < n; j++)
                if(!matrix[i][j]) matrix[0][j] = matrix[i][0] = 0;
        }
        
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j > 0; j--)
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            if(!col0) matrix[i][0] = 0;
        }
    }
};
