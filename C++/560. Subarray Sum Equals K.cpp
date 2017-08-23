class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int>m;
        int sum = 0;
        for(auto x: nums){
            m[sum]++;
            sum += x;
            if(m.count(sum - k) > 0) count += m[sum - k];
        }
        return count;
    }
};
