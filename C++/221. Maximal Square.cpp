// See detailed explanation in discuss.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int maxSquare = 0;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] != '0') maxSquare = max(maxSquare, findSquare(matrix, i, j));
        return maxSquare;
    }
    
    int findSquare(vector<vector<char>>& matrix, int r, int c){
        int row = r - 1;
        int col = c - 1;
        while(row >= 0 && col >= 0 && matrix[r][col] == '1' && matrix[row][c] == '1'){
            int i = row;
            int j = col;
            while(i < r && matrix[i][col] == '1') i++;
            while(j < c && matrix[row][j] == '1') j++;
            if(i != r || j != c) break;
            row--;
            col--;
        }
        return pow(r - row, 2);
    }
};
