class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int res = -1, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != target) continue;
            if(res == -1) res = i, count++;
            else{
                count++;
                if(rand() % count == 0) res = i;
            }
        }
        return res;
    }
    
private:
    vector<int>nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
