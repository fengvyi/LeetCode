// Final solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.size() == 0) return res;
        int minR = 0, maxR = matrix.size() - 1, minC = 0, maxC = matrix[0].size() - 1;
        while(minR <= maxR && minC <= maxC){
            for(int i = minC; i <= maxC; i++) res.push_back(matrix[minR][i]);
            minR++;
            for(int i = minR; i <= maxR; i++) res.push_back(matrix[i][maxC]);
            maxC--;
            for(int i = maxC; i >= minC && minR <= maxR; i--) res.push_back(matrix[maxR][i]);
            maxR--;
            for(int i = maxR; i >= minR && minC <= maxC; i--) res.push_back(matrix[i][minC]);
            minC++;
        }
        return res;
    }
};

// Solution 1.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.size() == 0) return res;
        pair<int,int>d(0, 1);
        vector<vector<int>>visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        DFS(matrix, 0, 0, d, res, visited);
        return res;
    }
    
    void DFS(vector<vector<int>>& matrix, int r, int c, pair<int,int>& d, vector<int>& res, vector<vector<int>>& visited){
        res.push_back(matrix[r][c]);
        if(res.size() == matrix.size() * matrix[0].size()) return;
        visited[r][c] = 1;
        int nextRow = r + d.first;
        int nextCol = c + d.second;
        if(nextRow == matrix.size() || nextCol == matrix[0].size() || nextCol < 0 || visited[nextRow][nextCol]) 
            d = nextDirection(d);
        DFS(matrix, r + d.first, c + d.second, d, res, visited);
    }
    
    //directions: right -> down -> left -> up;
    pair<int,int> nextDirection(pair<int,int>& d){
        pair<int, int>right(0, 1), down(1, 0), left(0, -1), up(-1, 0);
        return (d == right) ? down : (d == down) ? left : (d == left) ? up : right;
    }
};

// Solution 2.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.empty()) return res;
        DFS(matrix, 0, 0, matrix.size(), matrix[0].size(), res);
        return res;
    }
    
    void DFS(vector<vector<int>>& matrix, int r, int c, int maxR, int maxC, vector<int>& res){
        if(r >= maxR || c >= maxC) return;
        for(int i = c; i < maxC; i++) res.push_back(matrix[r][i]);
        for(int i = r + 1; i < maxR; i++) res.push_back(matrix[i][maxC - 1]);
        for(int i = maxC - 2; i > c && r != maxR - 1; i--) res.push_back(matrix[maxR - 1][i]);
        for(int i = maxR - 1; i > r && c != maxC - 1; i--) res.push_back(matrix[i][c]);
        DFS(matrix, r + 1, c + 1, maxR - 1, maxC - 1, res);
    }
};

// Solution 3.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.size() == 0) return res;
        DFS(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, res);
        return res;
    }
    
    void DFS(vector<vector<int>>& matrix, int minRow, int maxRow, int minCol, int maxCol, vector<int>& res){
        if(minRow > maxRow || minCol > maxCol) return;
        for(int i = minCol; i <= maxCol; i++) res.push_back(matrix[minRow][i]);
        minRow++;
        for(int i = minRow; i <= maxRow; i++) res.push_back(matrix[i][maxCol]);
        maxCol--;
        for(int i = maxCol; i >= minCol && minRow <= maxRow; i--) res.push_back(matrix[maxRow][i]);
        maxRow--;
        for(int i = maxRow; i >= minRow && minCol <= maxCol; i--) res.push_back(matrix[i][minCol]);
        minCol++;
        DFS(matrix, minRow, maxRow, minCol, maxCol, res);
    }
};
