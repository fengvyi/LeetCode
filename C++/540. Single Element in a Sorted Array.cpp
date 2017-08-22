class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int mid = (lo + hi) / 2;
        while(lo < hi - 2){
            if(nums[mid] == nums[mid + 1]) mid++;
            if((hi - mid) % 2) lo = mid + 1;
            else hi = mid;
            mid = (lo + hi) / 2;
        }
        return nums[lo] == nums[lo + 1] ? nums[hi] : nums[lo];
    }
};
