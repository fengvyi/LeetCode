class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int i = 0, j = 0, count = 0;
        unordered_map<int, int>m;
        int res = 0;
        while (j < tree.size()) {
            if (m[tree[j]] == 0) {
                ++count;
            }
            ++m[tree[j++]];
            while (count > 2) {
                if (--m[tree[i++]] == 0) {
                    --count;
                }
            }
            res = max(res, j - i);
        }
        return res;
    }
};
