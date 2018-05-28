// Solution 1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int lo = 0, hi = matrix.size() - 1;
        int mid = lo + (hi - lo) / 2 + 1;
        while(lo < hi){
            if(matrix[mid][0] > target) hi = mid - 1;
            else lo = mid;
            mid = lo + (hi - lo) / 2 + 1;
        }
        auto p = lower_bound(matrix[lo].begin(), matrix[lo].end(), target);
        return p != matrix[lo].end() && *p == target;
    }
};

// Solution 2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size(), l = 0, r = m * n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int val = matrix[mid/n][mid%n];
            if(val > target) r = mid - 1;
            else if(val < target) l = mid + 1;
            else return true;
        }
        return false;
    }
};

