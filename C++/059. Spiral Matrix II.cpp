class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n, vector<int>(n, 0));
        if(n == 0) return matrix;
        spiral(matrix, 0, n - 1, 0, n - 1, 1, n);
        return matrix;
    }
    
    void spiral(vector<vector<int>>& matrix, int minRow, int maxRow, int minCol, int maxCol, int k, int n){
        if(k > n * n) return;
        if(k == n * n){
            matrix[minRow][minCol] = k;
            return;
        }
        for(int i = minCol; i <= maxCol; i++) matrix[minRow][i] = k++;
        minRow++;
        for(int i = minRow; i <= maxRow; i++) matrix[i][maxCol] = k++;
        maxCol--;
        for(int i = maxCol; i >= minCol; i--) matrix[maxRow][i] = k++;
        maxRow--;
        for(int i = maxRow; i >= minRow; i--) matrix[i][minCol] = k++;
        minCol++;
        spiral(matrix, minRow, maxRow, minCol, maxCol, k, n);
    }
};
