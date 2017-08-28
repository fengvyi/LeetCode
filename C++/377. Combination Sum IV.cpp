class Solution {
private:
    unordered_map<int, int>m;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 1;
        if(m.count(target) > 0) return m[target];
        int sum = 0;
        for(auto  x: nums)
            if(target >= x)
                sum += combinationSum4(nums, target - x);
        m[target] = sum;
        return sum;
    }
};
