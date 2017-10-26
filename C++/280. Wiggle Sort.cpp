class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            if(i % 2 && nums[i - 1] > nums[i] || !(i % 2) && nums[i - 1] < nums[i]) swap(nums[i], nums[i - 1]);
    }
};
