class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int>idx, cnt;
        int degree = 0, minlen = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(!idx.count(nums[i])) idx[nums[i]] = i;
            if(++cnt[nums[i]] == degree) minlen = min(minlen, i - idx[nums[i]] + 1);
            if(cnt[nums[i]] > degree){
                degree = cnt[nums[i]];
                minlen = i - idx[nums[i]] + 1;
            }
        }
        return minlen;
    }
};
