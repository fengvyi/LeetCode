class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int n = nums.size();
        
        if (nums[n - 2] < nums[n - 1]) {
            return n - 1;
        } else if (nums[1] < nums[0]) {
            return 0;
        }
        
        int l = 1, r = n - 2, mid;
        while (l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid - 1] > nums[mid]) {
                r = mid - 1;
            } else if (nums[mid + 1] > nums[mid]) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
