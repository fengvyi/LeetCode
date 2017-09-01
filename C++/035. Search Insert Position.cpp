class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid = lo + (hi - lo) / 2;
        while(lo <= hi){
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
            mid = lo + (hi - lo) / 2;
        }
        return lo;
    }
};
