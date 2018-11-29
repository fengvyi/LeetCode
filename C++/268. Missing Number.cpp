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

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] > mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
