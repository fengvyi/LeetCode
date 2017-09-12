class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m - 1, j = n - 1; j >= 0;) nums1[i + j + 1] = (i < 0 || nums1[i] < nums2[j]) ? nums2[j--] : nums1[i--];
    }
};

// longer.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        while(i + j + 1 >= 0){
            nums1[i + j + 1] = i < 0 ? nums2[j--] : j < 0 ? nums1[i--] : nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
