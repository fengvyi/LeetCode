class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>res;
        if(nums.empty()){
            res.push_back((lower == upper) ? to_string(lower) : to_string(lower) + "->" + to_string(upper));
            return res;
        }
        int cur = lower;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            string s = "";
            if(nums[i] > cur) s += to_string(cur++);
            if(nums[i] > cur) s += "->" + to_string(nums[i] - 1);
            cur = nums[i] + 1;
            if(!s.empty()) res.push_back(s);
        }
        if(nums.back() == upper - 1) res.push_back(to_string(upper));
        else if(nums.back() < upper) res.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
        return res;
    }
};
