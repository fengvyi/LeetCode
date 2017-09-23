class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(auto x: nums) if(x) nums[j++] = x;
        while(j < nums.size()) nums[j++] = 0;
    }
};

// Without maintaining the relative order, min steps.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            while(nums[i] != 0) i++;
            while(nums[j] == 0) j--;
            swap(nums[i++], nums[j--]);
        }
    }
};
