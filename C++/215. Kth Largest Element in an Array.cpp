// Solution 1. Sort, O(nlogn).
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// Solution 2. Partition, O(n).
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            int p = partition(nums, lo, hi);
            if(p == k) break;
            if(p < k) lo = p + 1;
            else hi = p - 1;
        }
        return nums[k];
    }
    
private:
    int partition(vector<int>& nums, int lo, int hi){
        int pivot = nums[hi];    
        int i = lo;
        for(int j = lo; j < hi; j++)
            if(nums[j] <= pivot) swap(nums[i++], nums[j]);
        swap(nums[i], nums[hi]);
        return i;
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int pos = partition(nums, n - 1);
        int target = n - k;
        if (pos == target) {
            return nums[pos];
        } else if (pos < target) {
            vector<int>r(nums.begin() + pos + 1, nums.end());
            return findKthLargest(r, k);
        } else {
            vector<int>l(nums.begin(), nums.begin() + pos);
            return findKthLargest(l, k - (n - pos));
        }
    }
    
     int partition(vector<int>& nums, int end) {
         int i = 0, j = 0;
         while (j != end) {
             if (nums[j] < nums[end]) {
                 swap(nums[i], nums[j]);
                 ++i;
             }
             ++j;
         }
         swap(nums[i], nums[end]);
         return i;
     }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int l = 0, r = n - 1;
        while (l <= r) {
            int p = partition(nums, l, r);
            if (p == target) {
                return nums[p];
            } else if (p < target) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
    }
    
     int partition(vector<int>& nums, int l, int r) {
         int i = 0, j = 0;
         while (j != r) {
             if (nums[j] <= nums[r]) {
                 swap(nums[i], nums[j]);
                 ++i;
             }
             ++j;
         }
         swap(nums[i], nums[r]);
         return i;
     }
};
