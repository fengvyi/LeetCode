class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 0, j = 1, maxlen = 1;
        while(j < nums.size()){
            while(j < nums.size() && nums[j] > nums[j - 1]) j++;
            maxlen = max(maxlen, j - i);
            i = j++;
        }
        return maxlen;
    }
};
