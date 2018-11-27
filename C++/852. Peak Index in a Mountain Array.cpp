class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        // O(n)
        for (int i = 1; i < n - 1; ++i) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                return i;
            }
        }
        
        // O(logn)
        int l = 1, r = n - 2, mid;
        while (l <= r) {
            mid = l + (r - l)/2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            } else if (A[mid] > A[mid - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
