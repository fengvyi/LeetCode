class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size() - 1; i++){
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int lo = i + 1;
            for(int hi = nums.size() - 1; hi > lo; hi--){
                if(hi < nums.size() - 1 && nums[hi] == nums[hi + 1]) continue;
                while(nums[lo] < -(nums[i] + nums[hi])) lo++;
                if(lo < hi && (nums[i] + nums[lo] + nums[hi]) == 0) res.push_back({nums[i], nums[lo], nums[hi]});
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        for (int l = 0; l < n - 2; ++l) {
            if (l > 0 && nums[l] == nums[l - 1]) {
                continue;
            }
            int r = n - 1;
            int mid = l + 1;
            while (mid < r) {
                if (r < n - 1 && nums[r] == nums[r + 1]) {
                    --r;
                    continue;
                }
                
                while (r > mid && nums[l] + nums[mid] + nums[r] < 0) {
                    ++mid;
                }
                
                if (r > mid && nums[l] + nums[mid] + nums[r] == 0) {
                    res.push_back({nums[l], nums[mid], nums[r]});
                }
                --r;
            }
        }
        return res;
    }
};
