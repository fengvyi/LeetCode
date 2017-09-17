class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        k = abs(k);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(i < nums.size() - 1 && nums[i] == 0 && nums[i + 1] == 0) return true;
            if(k != 0 && sum % k == 0 && i > 0) return true;
            for(int j = 0; k != 0 && j*k < sum; j++)
                if(m.count(sum - j*k) > 0 && i - m[sum - j*k] > 0) return true;
            m[sum] = i;
        }
        return false;
    }
};
