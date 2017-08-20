class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlen = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        while(right < nums.size()){
            sum += nums[right++];
            while(sum >= s){
                minlen = min(minlen, right - left);
                sum -= nums[left++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
