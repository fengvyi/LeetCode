// My BF O(n^2) solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = 0, right = -1;
        for(int i = nums.size() - 1; i >= 0; i--)
            for(int j = i - 1; j >= 0; j--)
                if(nums[j] < nums[i] && (j > left || right == -1)) left = j, right = i;
        if(right == -1) sort(nums.begin(), nums.end());
        else{
            swap(nums[left], nums[right]);
            sort(nums.begin() + left + 1, nums.end());
        }
    }
};

// O(n) Solution from Stefan: https://discuss.leetcode.com/topic/19264/1-4-11-lines-c
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 1, k = i;
    while (i > 0 && nums[i-1] >= nums[i])
        i--;
    for (int j=i; j<k; j++, k--)
        swap(nums[j], nums[k]);
    if (i > 0) {
        k = i--;
        while (nums[k] <= nums[i])
            k++;
        swap(nums[i], nums[k]);
    }
}
