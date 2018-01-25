class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int a = 0, b = 0, idx = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > a){
                b = a;
                a = nums[i];
                idx = i;
            }
            else if(nums[i] > b) b = nums[i];
        }
        return a >= 2 * b ? idx : -1;
    }
};
