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
