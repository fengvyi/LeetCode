class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto& x: A){
            reverse(x.begin(), x.end());
            for(auto& y: x) y ^= 1;
        }
        return A;
    }
}; 
