class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>>g({{1,2,3,4,5,6,7,8,9}, 
                              {2,4,5,6,8},
                              {1,5,3,7,9,4,6},
                              {2,5,6,4,8},
                              {1,2,5,8,7,3,9},
                              {1,2,3,4,6,7,8,9},
                              {2,3,5,8,9,1,7},
                              {4,5,8,2,6},
                              {7,5,9,1,3,4,6},
                              {5,6,8,2,4}});
        
        int a = 0, b = 0, c = 0;
        vector<int>visited(10);
        dfs(g, m, n, 1, "1", a, visited);
        dfs(g, m, n, 2, "2", b, visited);
        dfs(g, m, n, 5, "5", c, visited);
        return a*4 + b*4 + c;
    }
    
    void dfs(vector<vector<int>> g, int m, int n, int from, string s, int& res, vector<int> visited) {
        if (s.size() > n) {
            return;
        }
        if (s.size() >= m) {
            ++res;
        }
        visited[from] = 1;
        unblock(g, from);
        for (int& x: g[from]) {
            if (!visited[x]) {
                s.push_back(x + '0');
                dfs(g, m, n, x, s, res, visited);
                s.pop_back();
                visited[x] = 0;
            }
        }
        visited[from] = 0;
    }
    
    
    void unblock(vector<vector<int>>& g, int num) {
        if (num == 2) {
            g[1].push_back(3);
            g[3].push_back(1);
        } else if (num == 4) {
            g[1].push_back(7);
            g[7].push_back(1);
        } else if (num == 5) {
            g[1].push_back(9);
            g[9].push_back(1);
            g[3].push_back(7);
            g[7].push_back(3);
            g[4].push_back(6);
            g[6].push_back(4);
            g[2].push_back(8);
            g[8].push_back(2);
        } else if (num == 6) {
            g[9].push_back(3);
            g[3].push_back(9);
        } else if (num == 8) {
            g[7].push_back(9);
            g[9].push_back(7);
        }
    }
};
