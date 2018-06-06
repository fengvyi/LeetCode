class Solution {
public:
    int longestMountain(vector<int>& A) {
        int l = 0, r = 1, res = 0, n = A.size();
        bool up = true;
        while(r < n){
            if(up && r - l > 1 && A[r] < A[r - 1]) up = false;
            if(up && (A[r] <= A[r - 1]) || !up && A[r] >= A[r - 1]){
                l = up ? r : --r;
                up = true;
            }
            r++;
            if(!up && r - l > 2) res = max(res, r - l);
        }
        return res;
    }
};
