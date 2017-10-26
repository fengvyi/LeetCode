/*
 Transition: Marks

 0 -> 0 : 0
 1 -> 1 : 1
 0 -> 1 : -1
 1 -> 0 : 2

Then update the board according to their marks.
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size() - 1, n = board[0].size() - 1;
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++){
                int neigh = cntNeighbor(board, m, n, i, j), cur = board[i][j];
                board[i][j] = (neigh > 3 || neigh < 2) && cur ? 2 : (neigh == 3 && !cur) ? -1 : cur;
            }
        
        for(auto& x: board)
            for(auto& y: x)
                y = (y == 2) ? 0 : (y == -1) ? 1 : y;
    }
    
    int cntNeighbor(vector<vector<int>>& board, int m, int n,  int r, int c){
        int cnt = 0;
        for(int i = max(0, r - 1); i <= min(m, r + 1); i++)
            for(int j = max(0, c - 1); j <= min(n, c + 1); j++)
                if((i != r || j != c) && board[i][j] > 0) cnt++;
        return cnt;
    }
};

// Or use the 2-bit to store the new state, idea from Stefan's post:(https://discuss.leetcode.com/topic/26112/c-o-1-space-o-mn-time).
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size() - 1, n = board[0].size() - 1;
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++){
                int neigh = cntNeighbor(board, m, n, i, j);
                if((neigh == 2 && board[i][j]) || neigh == 3) board[i][j] |= 2;
            }
        
        for(auto& x: board)
            for(auto& y: x)
                y >>= 1;
    }
    
    int cntNeighbor(vector<vector<int>>& board, int m, int n,  int r, int c){
        int cnt = 0;
        for(int i = max(0, r - 1); i <= min(m, r + 1); i++)
            for(int j = max(0, c - 1); j <= min(n, c + 1); j++)
                if((i != r || j != c) && board[i][j] & 1) cnt++;
        return cnt;
    }
};
