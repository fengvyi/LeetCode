// Solution 1.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, len = nums.size();
        while(j < nums.size()){
            while(j < nums.size() && sum < s) sum += nums[j++];
            if(i == 0 && sum < s) return 0;
            while(sum - nums[i]>= s) sum -= nums[i++];
            len = min(len, j - i);
            sum -= nums[i++];
        }
        return len;
    }
};

// Solution 2.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0, j = 0, len = INT_MAX, sum = 0;
        while(j < nums.size()){
            sum += nums[j++];
            while(sum >= s){
                len = min(len, j - i);
                sum -= nums[i++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
