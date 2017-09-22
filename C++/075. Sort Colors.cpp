/**
 * 1. Put '0's to the low position.
 * 2. Put '2's to the high position.
 * 3. Jump '1's.
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        for(int i = 0; i <= high;)
            if(nums[i] == 0) 
                swap(nums[i++], nums[low++]);
            else if(nums[i] == 2) 
                swap(nums[i], nums[high--]);
            else i++;
    }
};

// Shorter.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0, j = 0, k = nums.size() - 1; j <= k;)
            if(nums[j] == 0) swap(nums[i++], nums[j++]);
            else if(nums[j] == 2) swap(nums[j], nums[k--]);
            else j++;
    }
};

// Another solution.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size() - 1;
        for(int i = 0; i <= two; i++){
            while(nums[i] == 2 && i < two) swap(nums[i], nums[two--]);
            while(nums[i] == 0 && zero < i) swap(nums[i], nums[zero++]);
        }
    }
};

// And here is a O(k) space, O(k*n) time solution for k colors.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>color(3);
        for(int i = 0; i < 3; i++){
            if(i > 0) color[i] = color[i - 1];
            for(int j = color[i]; j < nums.size(); j++)
                while(color[i] <= j && nums[j] == i) swap(nums[j], nums[color[i]++]);
        }
    }
};
