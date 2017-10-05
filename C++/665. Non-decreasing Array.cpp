class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 1, j = 0; i < nums.size(); i++, j++)
            if(nums[j] > nums[i]){
                count++;
                if(j > 0 && nums[j - 1] > nums[i]) nums[i] = nums[j];
                else nums[j] = nums[i];
            }
        return count <= 1;
    }
};
