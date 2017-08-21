class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ways = 0;
        backtrack(nums, S, 0, 0, ways);
        return ways;
    }
    
    void backtrack(vector<int>& nums, int S, int sum, int pos, int& ways){
        if(pos == nums.size()){
            if(sum == S) ways++;
            return;
        }
        backtrack(nums, S, sum + nums[pos], pos + 1, ways);
        backtrack(nums, S, sum - nums[pos], pos + 1, ways);
    }
};
