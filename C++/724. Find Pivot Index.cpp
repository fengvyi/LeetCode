class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        for(int x: nums) right += x;
        for(int i = 0; i < n; left += nums[i], right -= nums[i], i++) 
            if(left == right - nums[i]) return i;
        return -1;
    }
};
