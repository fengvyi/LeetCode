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
