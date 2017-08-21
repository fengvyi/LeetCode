class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(auto& x: nums) if(!x) x = -1;
        unordered_map<int, int>m;
        m[0] = -1;
        int sum = 0, maxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(m.count(sum)) maxlen = max(maxlen, i - m[sum]);
            else m[sum] = i;
        }
        return maxlen;
    }
};
