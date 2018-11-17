class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int sum = 0, n = A.size();
        for (int& x: A) {
            sum += x;
        }
        sort(A.rbegin(), A.rend());
        for (int i = 1; i <= n/2; ++i) {
            if (sum*i%n == 0 && dfs(A, 0, i, sum*i/n, n)) {
                return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<int>& A, int pos, int count, int target, int& n) {
        if (count == 0) {
            return target == 0;
        }
        if (pos == n || target > A[pos] * count) {
            return false;
        }

        for (int i = pos; i < n; ++i) {
            if (target >= A[i] && dfs(A, i + 1, count - 1, target - A[i], n)) {
                return true;
            }
        }
        return false;
    }
};
