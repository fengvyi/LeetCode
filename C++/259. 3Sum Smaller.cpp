class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            for(int lo = i + 1, hi = nums.size() - 1; lo < hi; count += hi - lo++)
                while(lo < hi && nums[i] + nums[lo] + nums[hi] >= target) hi--;
        return count;
    }
};
