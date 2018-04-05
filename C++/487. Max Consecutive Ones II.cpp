class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, l = 0, r = 0, count = 0;
        while(r < nums.size()){
            if(nums[r++] == 0) count++;
            while(count > 1) if(nums[l++] == 0) count--;
            res = max(res, r - l);
        }
        return res;
    }
};
