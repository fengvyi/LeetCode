class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(visited[i][j] || board[i][j] == 'X') continue;
                bool surrounded = DFS(board, visited, i, j, m, n);
                if(surrounded) replace(board, i, j, m, n);
            }
    }
    
    bool DFS(vector<vector<char>>& board, vector<vector<int>>& visited, int r, int c, int m, int n){
        if(r < 0 || r == m || c < 0 || c == n) return false;
        if(board[r][c] == 'X' || visited[r][c]) return true;
        visited[r][c] = 1;
        bool L = DFS(board, visited, r, c - 1, m, n);
        bool R = DFS(board, visited, r, c + 1, m, n); 
        bool U = DFS(board, visited, r - 1, c, m, n); 
        bool D = DFS(board, visited, r + 1, c, m, n); 
        return L && R && U && D;
    }
    
    void replace(vector<vector<char>>& board, int r, int c, int m, int n){
        if(r < 0 || r == m || c < 0 || c == n || board[r][c] == 'X') return;
        board[r][c] = 'X';
        replace(board, r + 1, c, m, n);
        replace(board, r - 1, c, m, n);
        replace(board, r, c + 1, m, n);
        replace(board, r, c - 1, m, n);
    }
};
