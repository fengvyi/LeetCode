class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_map<int, int>m;
        for(auto x: nums){
            if(m[x]) continue;
            int left = m[x - 1];
            int right = m[x + 1];
            m[x + right] = m[x - left] = m[x] = left + right + 1;
            maxlen = max(maxlen, m[x]);
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>m;
        int res = 0;
        for (int& x: nums) {
            if (m[x]) {
                continue;
            }
            int l = m[x - 1];
            int r = m[x + 1];
            m[x] = l + r + 1;
            m[x - l] = l + r + 1;
            m[x + r] = l + r + 1;
            res = max(res, m[x]);
        }
        return res;
    }
};
