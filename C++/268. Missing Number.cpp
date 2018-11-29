class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, i = 0;
        for(auto& x: nums) res ^= ++i ^ x;
        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int& x: nums) {
            sum += x;
        }
        return (1 + n) * n/2 - sum;
    }
};
