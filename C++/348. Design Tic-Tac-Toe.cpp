class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->board.resize(n, vector<int>(n));
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        return checkWin(row, col, board.size(), player);
    }

private:
    vector<vector<int>>board;
    int checkWin(int row, int col, int n, int player){
        int r = 0, c = 0, i = 0, j = 0, x = 0, y = n - 1;
        while(r < n && board[r][col] == player) r++;
        while(c < n && board[row][c] == player) c++;
        if(row == col)  while(i < n && board[i][j] == player) i++, j++;
        if(row == n - col - 1) while(x < n && board[x][y] == player) x++, y--;
        return r == n || c == n || i == n || x == n ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
