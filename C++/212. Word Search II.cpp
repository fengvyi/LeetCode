// Solution 1
// Brute force
// Runime: 462 ms

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>res;
        unordered_map<char, vector<string>>m;
        for(auto x: words) m[x[0]].push_back(x);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(m[board[i][j]].size() > 0)
                    for(auto x: m[board[i][j]]){
                        bool found = false;
                        backtrack(board, 1, i, j, board.size(), board[0].size(), x, found);
                        if(found && find(res.begin(), res.end(), x) == res.end()) res.push_back(x);
                    } 
        return res;
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

// Solution 2
// Add Trie, inspired by Trie implementation in this [thread](https://discuss.leetcode.com/topic/13463/maybe-the-code-is-not-too-much-by-using-next-26-c).
// Runtime: 35 ms. (Beats 95.58% of C++ solutions.)

struct TrieNode{
    string word;
    TrieNode* next[26];
};

class Solution {
private:
    TrieNode* root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>res;
        buildTrie(words);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                backtrack(board, res, i, j, board.size() - 1, board[0].size() - 1, root);
        return res;
    }
    
    void backtrack(vector<vector<char>>& board, vector<string>& res, int r, int c, int m, int n, TrieNode* p){
        if(r < 0 || c < 0 || r > m || c > n || board[r][c] == '0'|| !p->next[board[r][c] - 'a']) return;
        p = p->next[board[r][c] - 'a'];
        if(p->word.size() > 0){
            res.push_back(p->word);
            p->word = "";
        }
        char tmp = board[r][c];
        board[r][c] = '0';
        backtrack(board, res, r - 1, c, m, n, p);
        backtrack(board, res, r + 1, c, m, n, p);
        backtrack(board, res, r, c + 1, m, n, p);
        backtrack(board, res, r, c - 1, m, n, p);
        board[r][c] = tmp;
    }
    
    void buildTrie(vector<string>& words){
        root = new TrieNode();
        for(auto x: words){
            TrieNode* p = root;
            for(auto c: x){
                if(!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->word = x;
        }
    }
};
