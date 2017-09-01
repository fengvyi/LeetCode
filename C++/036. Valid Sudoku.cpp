class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_map<char, int>>row(n);
        vector<unordered_map<char, int>>col(n);
        vector<vector<unordered_map<char, int>>>sub(n/3, vector<unordered_map<char, int>>(n/3));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                char c = board[i][j];
                if(c == '.') continue;
                if(row[i][c]++ > 0 || col[j][c]++ > 0 || sub[i/3][j/3][c]++ > 0) return false;
            }
        return true;
    }
};
