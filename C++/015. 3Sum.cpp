class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        int hi = nums.size() - 1;
        for(int i = 0; i < hi - 1; i++){
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            int j = i + 1;
            while(nums[i] + nums[j] + nums[hi] > 0) hi--;
            for(int k = hi; k > j; k--){
                if(k < nums.size() - 1 && nums[k] == nums[k + 1]) continue;
                while(nums[j] < -(nums[i] + nums[k])) j++;
                if(j < k && (nums[i] + nums[j] + nums[k]) == 0) res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};
