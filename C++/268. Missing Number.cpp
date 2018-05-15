class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, i = 0;
        for(auto& x: nums) res ^= ++i ^ x;
        return res;
    }
};
