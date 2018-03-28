class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        vector<int>k(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i - A[i]; j++) k[j]++;
            for(int j = i + 1; j <= i + n - A[i] && j < n; j++) k[j]++;
        }
        return max_element(k.begin(), k.end()) - k.begin();
    }
};
