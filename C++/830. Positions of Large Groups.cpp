class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>>res;
        int l = 0, r = 0, n = S.size();
        while(l < n){
            while(r < n && S[r] == S[l]) r++;
            if(r  - l >= 3) res.push_back({l, r - 1});
            l = r;
        }
        return res;
    }
};
