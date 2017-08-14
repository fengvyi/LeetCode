class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(auto x: nums) if(x) nums[j++] = x;
        while(j < nums.size()) nums[j++] = 0;
    }
};
