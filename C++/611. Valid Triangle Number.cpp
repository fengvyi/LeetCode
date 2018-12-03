class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                for(int k = j + 1; k < n; k++)
                    if(nums[i] + nums[j] > nums[k]) count++;
        return count;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, n = nums.size();
        for(int i = n - 1; i > 1; --i) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    count += r - l;
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return count;
    }
};
