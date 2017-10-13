class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>res;
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = pos - 1, j = pos;
        while(k--)
            (i >= 0 && (j == arr.size() || abs(arr[i] - x) <= abs(arr[j] - x))) ? i-- : j++;
        res.assign(arr.begin() + i + 1, arr.begin() + j);
        return res;
    }
};
