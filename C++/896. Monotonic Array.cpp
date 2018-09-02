class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool a(true), b(true);
        int n = A.size();
        for(int i = 0; i < n - 1 && (a || b); ++i){
            if(A[i] > A[i + 1]) a = false;
            if(A[i] < A[i + 1]) b = false;
        }
        return a || b;
    }
};
