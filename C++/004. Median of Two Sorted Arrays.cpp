class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int lo = 0, hi = m, mid = (m + n + 1)/2;
        while(lo <= hi){
            int i = (lo + hi)/2;
            int j = mid - i;
            if(i < m && nums2[j - 1] > nums1[i]) 
                lo = i + 1;
            else if(i > 0  && nums1[i - 1] > nums2[j])
                hi = i - 1;
            else{
                int maxLeft = (i == 0) ? nums2[j - 1] : (j == 0) ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]); 
                int minRight = (i == m) ? nums2[j] : (j == n) ? nums1[i] : min(nums1[i], nums2[j]);
                return (m + n) % 2 ? maxLeft : (maxLeft + minRight) / 2.0;
            }
        }
    }
};
