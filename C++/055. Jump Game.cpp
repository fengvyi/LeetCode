class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            distance = max(distance, i + nums[i]);
            if(distance == i) return false;
        }
        return true;
    }
};
