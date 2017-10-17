class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int>res;
        vector<vector<int>>matrix(m, vector<int>(n));
        int tag = 0, count = 0;
        for(auto x: positions) addLand(matrix, m, n, x.first, x.second, tag, count, res);
        return res;
    }
    
    void addLand(vector<vector<int>>& matrix, int m, int n, int r, int c, int& tag, int& count, vector<int>& res){
        unordered_set<int>s;
        vector<int>dir(4);
        if(c - 1 >= 0) dir[0] = matrix[r][c - 1];
        if(c + 1 < n)  dir[1] = matrix[r][c + 1];
        if(r - 1 >= 0) dir[2] = matrix[r - 1][c];
        if(r + 1 < m)  dir[3] = matrix[r + 1][c];
        for(auto x: dir) if(x) s.insert(x);
        matrix[r][c] = s.empty() ? ++tag : *s.begin();
        count -= s.size() - 1;
        res.push_back(count);
        if(s.size() > 1){
            BFS(matrix, m, n, r, c - 1, *s.begin());
            BFS(matrix, m, n, r, c + 1, *s.begin());
            BFS(matrix, m, n, r - 1, c, *s.begin());
            BFS(matrix, m, n, r + 1, c, *s.begin());
        }
    }
    
    void BFS(vector<vector<int>>& matrix, int m, int n, int r, int c, int tag){
        if(r < 0 || c < 0 || r == m || c == n || matrix[r][c] == 0 || matrix[r][c] == tag) return;
        matrix[r][c] = tag;
        BFS(matrix, m, n, r, c - 1, tag);
        BFS(matrix, m, n, r, c + 1, tag);
        BFS(matrix, m, n, r - 1, c, tag);
        BFS(matrix, m, n, r + 1, c, tag);
    }
};
