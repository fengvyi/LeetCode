// Brute Force, O(n^2).
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = 0;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];
                if(sum == k) len = max(len, j - i + 1);
            }
        }
        return len;
    }
};

// O(n).
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int sum = 0;
        int maxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(!m.count(sum)) m[sum] = i;
            if(sum == k) maxlen = i + 1;
            else if(m.count(sum - k) > 0) maxlen = max(maxlen, i - m[sum - k]);
        }
        return maxlen;
    }
};
