class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0, product = 1;
        for(int i = 0, j = 0, pre = 0; j < nums.size(); i++, pre = j, j = max(i, j)){
            while(j < nums.size() && product * nums[j] < k) product *= nums[j++];
            count += (long)(j - pre) * (1 + (j - pre)) / 2 + (j - pre) * (pre - i);
            product = max(product / nums[i], 1);
        }
        return count;
    }
};
