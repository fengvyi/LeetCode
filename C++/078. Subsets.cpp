class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        backtrack(nums, 0, vector<int>(), res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int k, vector<int> subset, vector<vector<int>>& res){
        if(k == nums.size()){
            res.push_back(subset);
            return;
        }
        backtrack(nums, k+1, subset, res);
        subset.push_back(nums[k]);
        backtrack(nums, k+1, subset, res);
    }
};
