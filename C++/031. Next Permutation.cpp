class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = 0, right = -1;
        for(int i = nums.size() - 1; i >= 0; i--)
            for(int j = i - 1; j >= 0; j--)
                if(nums[j] < nums[i]) if(j > left || right == -1) left = j, right = i;
        if(right == -1) sort(nums.begin(), nums.end());
        else{
            swap(nums[left], nums[right]);
            sort(nums.begin() + left + 1, nums.end());
        }
    }
};
