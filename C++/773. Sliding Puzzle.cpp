class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string>visited;
        vector<vector<int>>dst({{1,2,3}, {4,5,0}});
        string target = toString(dst);
        
        int level = 0;
        
        queue<vector<vector<int>>>cur, next;
        
        cur.push(board);
        
        while(!cur.empty()) {
            auto node = cur.front();
            cur.pop();
            
            string s = toString(node);
            
            if (s == target) {
                return level;
            }
            
            visited.insert(s);
            
            auto nextStates = nextState(node);
            
            for (auto v: nextStates) {
                string t = toString(v);
                if (!visited.count(t)) {
                    next.push(v);
                }
            }
            if (cur.empty()) {
                ++level;
                swap(cur, next);
            }
        }
        return -1;
    }
    
    vector<vector<vector<int>>> nextState(vector<vector<int>>& board) {
        vector<vector<vector<int>>>res;
        auto pos = findZero(board);
        int r = pos[0];
        int c = pos[1];
        
        int left  = c - 1;
        int right = c + 1;
        int up    = r - 1;
        int down  = r + 1;
        
        if (left >= 0) {
            swap(board[r][left], board[r][c]);
            res.push_back(board);
            swap(board[r][left], board[r][c]);
        } 
        if (right < 3) {
            swap(board[r][right], board[r][c]);
            res.push_back(board);
            swap(board[r][right], board[r][c]);
        }
        if (up >= 0) {
            swap(board[up][c], board[r][c]);
            res.push_back(board);
            swap(board[up][c], board[r][c]);
        }
        if (down < 2) {
            swap(board[down][c], board[r][c]);
            res.push_back(board);
            swap(board[down][c], board[r][c]);
        }
        return res;
    }
    
    vector<int> findZero(vector<vector<int>>& board) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    return {i, j};
                }
            }
        }
    }
    
    string toString(vector<vector<int>>& v) {
        string s;
        for (auto x: v) {
            for (auto y: x) {
                s += to_string(y) + ",";
            }
        }
        return s;
    }
};
