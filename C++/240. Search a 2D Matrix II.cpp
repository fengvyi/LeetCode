// Solution 1. Binary Search, 103 ms.
// Do binary seach on **first** column to get a row position - `lo`, rows **after** `lo` won't contain the target value because rows are sorted.
// Do binary seach on **last** column to get a row position - `hi`, rows **before** `hi` won't contain the target value because rows are sorted.
// Do binary search on rows between `lo` and `hi`.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int lo = BS(matrix, 0, target), hi = BS(matrix, matrix[0].size() - 1, target);
        for(int i = min(lo, hi); i <= max(lo, hi); i++){
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(it != matrix[i].end() && *it == target) return true;
        }
        return false;
    }
    
    int BS(vector<vector<int>>& matrix, int col, int target){
        int lo = 0, hi = matrix.size() - 1, mid = lo + (hi - lo) / 2;
        while(lo <= hi){
            if(matrix[mid][col] > target) hi = mid - 1;
            else lo = mid + 1;
            mid = lo + (hi - lo) / 2;
        }
        return max(0, hi);
    }
};

// Solution 2. Start at top-right position and go left or go down, 59 ms.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int r = 0, c = matrix[0].size() - 1;
        while(r < matrix.size() && c >= 0){
            if(matrix[r][c] == target) return true;
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};
