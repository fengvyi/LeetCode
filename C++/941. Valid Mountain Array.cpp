class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0, n = A.size();
        if (n < 3) {
            return false;
        }
        while (i < n - 1 && A[i] < A[i + 1]) {
            ++i;
        }
        if (i == 0 || i == n - 1) {
            return false;
        }
        while (i < n - 1 && A[i] > A[i + 1]) {
            ++i;
        }
        return i == n - 1;
    }
};
