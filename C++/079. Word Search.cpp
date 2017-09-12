// Solution 1
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0|| word.size() == 0) return true;
        bool find = false;
        vector<vector<int>>visited(board.size(), vector<int>(board[0].size(),0));
        for(int i = 0 ; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                     find = backtrack(i, j, board, word, visited);
                     if(find) return find;
                }
            }
        return find;
    }
    
    bool backtrack(int i, int j, vector<vector<char>>& board, string word, vector<vector<int>>& visited){
        if(word.size() == 0) return true;
        if(i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) return false;
        if(visited[i][j]) return false;
        bool find = false;
        if(board[i][j] == word[0]){
            word.erase(word.begin());
            visited[i][j] = 1;
            find = backtrack(i-1,j,board,word,visited) || backtrack(i,j-1,board,word,visited) 
                || backtrack(i+1,j,board,word,visited) || backtrack(i,j+1,board,word,visited);
            visited[i][j] = 0;
        }
       return find;
    }
};

// Solution 2
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        bool found = false;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]) backtrack(board, 1, i, j, m, n, word, found);
                if(found) return true;
            }
        return false;
    }
    
    void backtrack(vector<vector<char>>& board, int pos, int r, int c, int m, int n, string& word, bool& found){
        if(board[r][c] == '0' || found) return;
        if(pos == word.size()){
            found = true;
            return;
        }
        char tmp = board[r][c];
        board[r][c] = '0';
        if(r - 1 >= 0 && board[r - 1][c] == word[pos]) backtrack(board, pos + 1, r - 1, c, m, n, word, found);
        if(r + 1 < m  && board[r + 1][c] == word[pos]) backtrack(board, pos + 1, r + 1, c, m, n, word, found);
        if(c + 1 < n  && board[r][c + 1] == word[pos]) backtrack(board, pos + 1, r, c + 1, m, n, word, found);
        if(c - 1 >= 0 && board[r][c - 1] == word[pos]) backtrack(board, pos + 1, r, c - 1, m, n, word, found);
        board[r][c] = tmp;
    }
};

// Solution 3.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == word[0] && BFS(board, i, j, m, n, 0, word)) return true;
        return false;
    }
    
    bool BFS(vector<vector<char>>& board, int r, int c, int m, int n, int len, string& word){
        if(len == word.size()) return true;
        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] == '#' || board[r][c] != word[len]) return false;
        char tmp = board[r][c];
        board[r][c] = '#';
        bool found =  BFS(board, r + 1, c, m, n, len + 1, word) || BFS(board, r, c + 1, m, n, len + 1, word) ||
                      BFS(board, r - 1, c, m, n, len + 1, word) || BFS(board, r, c - 1, m, n, len + 1, word);
        board[r][c] = tmp;
        return found;
    }
};
