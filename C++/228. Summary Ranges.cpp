class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        for(int i = 0, j = 1; i < nums.size(); i = j, j = i + 1){
            while(j < nums.size() && nums[j] == nums[j - 1] + 1) j++;
            res.push_back((j == i + 1) ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[j - 1]));
        }
        return res;
    }
};
