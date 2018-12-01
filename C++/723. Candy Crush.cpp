class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        while (crush(board, m, n)) {
            drop(board, m, n);
        }
        return board;
    }
    
    bool crush(vector<vector<int>>& board, int m, int n) {
        vector<vector<int>>copy(board);
        bool canBeCrushed = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 0) {
                    continue;
                }
                int r = i, c = j, count = 0;
                // check horizontal
                while (c < n && board[i][c] == board[i][j]) {
                    ++count;
                    ++c;
                }
                if (count >= 3) {
                    canBeCrushed = true;
                    while (c > j) {
                        copy[i][--c] = 0;
                    }
                }
                count = 0;
                // check vertical
                while (r < m && board[r][j] == board[i][j]) {
                    ++count;
                    ++r;
                }
                if (count >= 3) {
                    canBeCrushed = true;
                    while (r > i) {
                        copy[--r][j] = 0;
                    }
                }
            }
        }
        board = copy;
        return canBeCrushed;
    }
    
    void drop(vector<vector<int>>& board, int m, int n) {
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 0) {
                    // drop
                    int r = i, c = j;
                    while (r >= 0 && board[r][c] == 0) {
                        --r;
                    }
                    if (r >= 0) {
                        swap(board[i][j], board[r][c]);
                    }
                }
            }
        }
    }
};
