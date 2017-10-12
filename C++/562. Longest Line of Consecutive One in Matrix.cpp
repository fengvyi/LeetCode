class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        int maxlen = 0, m = M.size(), n = M[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(M[i][j]) BFS(M, i, j, m, n, maxlen);
        return maxlen;
    }
    
    void BFS(vector<vector<int>>& M, int r, int c, int m, int n, int& maxlen){
        int h = 1, v = 1, d_left = 1, d_right = 1;
        for(int i = c + 1; i < n && M[r][i]; i++) h++;
        for(int i = r + 1; i < m && M[i][c]; i++) v++;
        for(int i = r + 1, j = c - 1; i < m && j >= 0 && M[i][j]; i++, j--) d_left++;
        for(int i = r + 1, j = c + 1; i < m && j < n && M[i][j]; i++, j++) d_right++;
        maxlen = max(maxlen, max(max(h, v), max(d_left, d_right)));
    }
};
