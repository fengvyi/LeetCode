class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int>idx;
        int n = row.size();
        for (int i = 0; i < n; ++i) {
            idx[row[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < n; i += 2) {
            if (!isCouple(row[i], row[i + 1])) {
                int val = findMyCouple(row[i]);
                swap(row[i + 1], row[idx[val]]);
                // Update idx
                idx[row[idx[val]]] = idx[val];
                idx[row[i + 1]] = i + 1;
                ++res;
            }
        }
        return res;
    }
    
    bool isCouple(int a, int b) {
        return (!(a%2) && (b == a + 1)) || (!(b%2) && (a == b + 1));
    }
    
    int findMyCouple(int x) {
        return x%2 ? x - 1 : x + 1;
    }
};
